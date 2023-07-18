/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:13:48 by sokaraku          #+#    #+#             */
/*   Updated: 2023/07/17 10:13:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_lentotal(int size, char **strs, char *sep)
{
	int	i;
	int	str_len;

	str_len = (ft_strlen(sep) * (size - 1)) + 1;
	i = -1;
	while (++i < size)
		str_len += ft_strlen(strs[i]);
	return (str_len);
}

void	ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_len;
	int		i;
	char	*str;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	str_len = ft_lentotal(size, strs, sep);
	str = (char *)malloc(str_len * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	i = -1;
	while (++i < size - 1)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
	}
	ft_strcat(str, strs[i]);
	return (str);
}
/*
int	main(int argc, char *argv[])
{
	char	**strs;
	int	i;
	strs = (char **)malloc(100 * sizeof(char *));
	i = 1;
	while (++i < argc - 1)
		strs[i - 2] = argv[i];
	printf("%s", ft_strjoin(atoi(argv[1]), strs, argv[argc - 1]));
}
*/
