/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:14:38 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/15 16:14:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
int		spaces_sign_check(int i, int *sign, char *str);
int		btoi(char c, char *base);
int		ft_atoi_base(char *str, char *base);

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	swap(char *a, char *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_revert_tab(char *tab, int size)
{
	int		i;
	float	limit;

	i = 0;
	limit = size / 2;
	while (i < limit)
	{
		swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

char	*itoa(long int *inbr, char *temp, char *base_to, int len)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (*inbr < 0)
	{
		sign *= -1;
		*inbr = -*inbr;
	}
	while (*inbr > 0)
	{
		temp[i++] = base_to[*inbr % len];
		*inbr /= len;
	}
	if (sign < 0)
		temp[i++] = '-';
	ft_revert_tab(temp, ft_strlen(temp));
	return (temp);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	inbr;
	int			len;
	char		*res;
	char		temp[40];

	inbr = ft_atoi_base(nbr, base_from);
	len = ft_strlen(base_to);
	res = itoa(&inbr, temp, base_to, len);
	res = ft_strdup(temp);
	return (res);
}

/*int	main(void)
{
	char bin[] = "01";
	char oct[] = "marinxyz";
	char hex[] = "0123456789ABCDEF";
	char dec[] = "0123456789";

	char test1[] = " ---101010xxx";
	printf("101010 en bin\t= %s en hex\n", ft_convert_base(test1, bin, hex));
	char test2[] = " ---xr.xxx";
	printf("xr en oct\t= %s en hex\n", ft_convert_base(test2, oct, hex));
	char test4[] = " -----2Axxx";
	printf("2A en hex\t= %s en bin\n", ft_convert_base(test4, hex, bin));
	char test3[] = " 2147483647xxx";
	printf("int max en dec\t= %s en bin\n", ft_convert_base(test3, dec, bin));

	return (0);
}

void	neg_check(int *sign, long int *inbr)
{
	if (*inbr < 0)
	{
		*sign *= -1;
		*inbr = -*inbr;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	inbr;
	int			len;
	int			sign;
	char		*res;
	char		temp[40];

	i = 0;
	inbr = ft_atoi_base(nbr, base_from);
	len = ft_strlen(base_to);
	sign = 1;
	neg_check(&sign, &inbr);
	while (inbr > 0)
	{
		temp[i++] = base_to[inbr % len];
		inbr /= len;
	}
	if (sign < 0)
		temp[i++] = '-';
	temp[i] = '\0';
	ft_revert_tab(temp, ft_strlen(temp));
	res = ft_strdup(temp);
	return (res);
}*/