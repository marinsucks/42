#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
	: _fs(","), _file("data.csv"), _current_line(1)
{}

BitcoinExchange::BitcoinExchange(std::string & data)
	: _fs(","), _file(data), _current_line(1)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy)
	: _data(copy._data), _fs(copy._fs), _file(copy._file), _current_line(copy._current_line)
{}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & copy)
{
	if (this != &copy)
	{
		_data = copy._data;
		_fs = copy._fs;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	_data.clear();
}

void BitcoinExchange::checkFormat(std::string line)
{
	size_t min_len = 10 + _fs.length(); // 10 is the length of the date format "YYYY-MM-DD"
	if (line.length() < min_len)
		throw InvalidFormat();

	for (int i = 0; i < 10; ++i) 
	{
		if (((i == 4 || i == 7) && line[i] != '-')
			|| ((i != 4 && i != 7) && !isdigit(line[i])))
			throw InvalidFormat();
	}

	if (line.substr(10, _fs.length()) != _fs)
		throw InvalidFormat();

	bool decimalPointFound = false;
	for (size_t i = min_len; i < line.length(); ++i)
	{
		if ((!isdigit(line[i]) && line[i] != '.' && line[i] != '\n')
			|| (line[i] == '.' && decimalPointFound))
			throw InvalidValue();
		if (line[i] == '.')
			decimalPointFound = true;
	}
}

void BitcoinExchange::checkDate(std::string date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				throw InvalidDate();
			break;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				throw InvalidDate();
			break;
		case 2:
			if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
				throw InvalidDate();
			break;
		default:
			throw InvalidDate();
	}
}

void BitcoinExchange::parseData()
{
	std::ifstream infile(_file.c_str());
	if (!infile.is_open() || !infile.good())
		throw InvalidFile();

	std::string line;
	std::string date;
	double value;

	_current_line = 1;
	std::getline(infile, line);
	if (!line.find(_fs))
		throw InvalidFormat();

	while (std::getline(infile, line))
	{
		checkFormat(line);

		date = line.substr(0, line.find(_fs));
		checkDate(date);

		value = std::strtod(line.substr(line.find(_fs) + _fs.length()).c_str(), NULL);

		if (value < 0)
			throw InvalidValue();

		_data[date] = value;
		_current_line++;
	}

	if (_current_line < 2)
		throw InvalidFile();
	
	infile.close();
}

void BitcoinExchange::printConversion(std::string date, double value)
{
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it == _data.end())
	{
		std::cerr << "Error: Date not found in data." << std::endl;
		return;
	}
	if (it == _data.begin() && it->first > date)
		throw InvalidTooOld();
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::parseInput()
{
	std::ifstream infile(_file.c_str());
	if (!infile.is_open() || !infile.good())
		throw InvalidFile();

	std::string line;
	std::string date;
	double value;

	_current_line = 1;
	std::getline(infile, line);
	if (!line.find(_fs))
		throw InvalidFormat();
	_current_line++;

	while (std::getline(infile, line))
	{
		try
		{
			checkFormat(line);
			date = line.substr(0, line.find(_fs));
			checkDate(date);
			value = std::strtod(line.substr(line.find(_fs) + _fs.length()).c_str(), NULL);
			if (value < 0)
				throw InvalidValue();
			printConversion(date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << _file << ":" << _current_line << ":\terror: " << e.what() << std::endl;
		}
		_current_line++;
	}

	if (_current_line < 2)
		throw InvalidFile();
	
	infile.close();
}

void BitcoinExchange::run(std::string infile)
{
	std::cout.precision(10); //avoid rounding double value to first decimal
	try
	{
		parseData();

		_file = infile;
		_fs = " | ";
		parseInput();

		//for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
		//	std::cout << it->first << "," << it->second << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _file << ":" << _current_line << ": error: " << e.what() << std::endl;
	}


}


const char * BitcoinExchange::InvalidFile::what() const throw() 
{
	return "invalid file";
}

const char * BitcoinExchange::InvalidFormat::what() const throw()
{
	return "invalid line format";
}

const char * BitcoinExchange::InvalidDate::what() const throw()
{
	return "invalid date";
}

const char * BitcoinExchange::InvalidValue::what() const throw()
{
	return "invalid value";
}

const char * BitcoinExchange::InvalidTooOld::what() const throw()
{
	return "required date is older than the first date in data (are you Marty McFly?)";
}
