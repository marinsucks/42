if [ $# -lt 3 ]; then 
	echo "Usage: $0 [infile] [cmd1] [cmd2]" 
	exit 1 
fi
rm pipex_outfile bash_outfile
touch pipex_outfile bash_outfile
./pipex $1 $2 $3 pipex_outfile
< $1 $2 | $3 > bash_outfile

if diff pipex_outfile bash_outfile >/dev/null; then
	echo "\033[32m[diff ok]\033[0m"
else
	echo "\033[31m[diff ko]\033[0m"
fi
