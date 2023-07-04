/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:23:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/02 18:23:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*lowcase_me(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	is_alphanum(char chr)
{
	if (!((chr >= '0' && chr <= '9') || (chr >= 'a' && chr <= 'z')
			|| (chr >= 'A' && chr <= 'Z')))
	{
		return (0);
	}
	return (1);
}

int	is_alpha(char chr)
{
	if (!((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	lowcase_me(str);
	if (is_alpha(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (!is_alphanum(str[i - 1]) && is_alpha(str[i]))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

/*int main()
{
	char str1[]= ";nan ;Non :nan |nan |Not 'n 'M `o `O";
	char str2[]= "salut, commEnt tu vas ? 42mots que-deux ";
	char str3[]= "wtf";
	char str4[]= "ayo;";
	char str5[]= "nique";
	char str6[] = "yo c'est le w33K3nD ou+quOi\n";
	char str7[] = " salut, comment tu vas ? 42mots que-deux";
	char str8[]= "t";
	char str9[]= "7";
	char str10[]= " ";

	ft_strcapitalize(str1);
	ft_strcapitalize(str2);
	ft_strcapitalize(str3);
	ft_strcapitalize(str4);
	ft_strcapitalize(str5);
	ft_strcapitalize(str6);
	ft_strcapitalize(str7);
	ft_strcapitalize(str8);
	ft_strcapitalize(str9);
	ft_strcapitalize(str10);
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	str1, str2, str3, str4, str5, str6, str7, str7, str8, str9, str10);
}*/
