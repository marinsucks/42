/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:00:43 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/03 10:00:45 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &"\\", 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
			ft_convert_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

/*int main()
{
	ft_putstr_non_printable("Yo je \n teste des tru\0cs abcdefghijklmnop 5\0");
	return (0);
}*/
