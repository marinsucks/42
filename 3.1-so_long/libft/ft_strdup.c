/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:37:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/26 11:39:14 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	len = ft_strlen(s1) + 1;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (0);
	len = 0;
	while (s1[len])
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = 0;
	return (dest);
}

char	*ft_strndup(const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (src[i] && i < size)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_tabdup(char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	new_tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
		{
			ft_freetab(new_tab);
			return (0);
		}
		i++;
	}
	new_tab[i] = 0;
	return (new_tab);
}
