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
	if ((chr < '0' && '9' > chr)
		&& (chr < 'a' && 'z' > chr)
		&& (chr < 'A' && 'Z' > chr))
	{
		return (0);
	}
	return (1);
}

int	is_alpha(char chr)
{
	if (chr < 'A'
		|| (chr > 'Z' && chr < 'a')
		|| chr > 'z')
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
		if (!is_alphanum(str[i - 1])
			&& is_alpha(str[i]))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*int main()
{
	char str[] = "yo c'est le w33K3nD ou+quOi\n";
	char str2[] = " salut, comment tu vas ? 42mots quarante-deux";
	char str3[]= "t";
	char str4[]= "7";
	char str5[]= " ";
	
	ft_strcapitalize(str);
	ft_strcapitalize(str2);
	ft_strcapitalize(str3);
	ft_strcapitalize(str4);
	ft_strcapitalize(str5);
	printf("%s\n%s\n%s\n%s\n%s\n", str, str2, str3, str4, str5);
}
*/