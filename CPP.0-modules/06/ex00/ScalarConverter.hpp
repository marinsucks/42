/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:08:18 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/21 17:11:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		
	public:
		static void convert(const std::string& str);
};
