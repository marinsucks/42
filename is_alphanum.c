/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alphanum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:03:44 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 20:03:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Here are two functions. 
//Both analyse input and determine if it is an alphanum or not, outputing 1 for yes and 0 for no.
//The first one takes a character while the second one takes a string as input.

#include <stdio.h>

int	is_alphanum_char(char str)
{
	if (!((str >= '0' && str <= '9')
    	|| (str >= 'a' && str <= 'z')
    	|| (str >= 'A' && str <= 'Z')))
	{
		return (0);
	}
	return (1);
}

int	is_alphanum_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && '9' <= str[i])
			|| (str[i] >= 'a' && 'z' <= str[i])
			|| (str[i] >= 'A' && 'Z' <= str[i])))
		{
			return (0);
		}
		i++;
	}
	return (1);
}


//main for test
int main()
{
	printf("%i", is_alphanum_char('C'));
	printf("%i", is_alphanum_char('a'));
	printf("%i", is_alphanum_char('7'));
	printf("%i", is_alphanum_char('\n'));
	printf("%i", is_alphanum_string("0nly4lph4num"));
	printf("%i", is_alphanum_string("not\n4lph4num"));



	return 0;
}
