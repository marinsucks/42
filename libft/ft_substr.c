/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:11:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/13 16:11:22 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void ft_sublen(char const *s, unsigned int start, size_t *len)
{
	size_t	slen;

	slen = ft_strlen(s) + 1;
	if (start > slen || len == 0)
		*len = 0;
	else if (start == slen)
		*len = 1;
	else if (*len > (slen - start))
		*len = slen - start;
	else
		*len += 1;
	//printf("len = %zu\n", *len);
}
*/
static void	ft_sublen(char const *s, unsigned int start, size_t *len)
{
	size_t	slen;

	slen = ft_strlen(s) + 1;
	if (start > slen)
		*len = 1;
	else if (*len > (slen - start))
		*len = slen - start;
	else
		*len += 1;
	printf("len = %zu\n", *len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	ft_sublen(s, start, &len); // len prend +1
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	while (s[start] && --len)
		res[i++] = s[start++];
	res[i] = 0;
	return res;
}

/*#include <stdio.h>

int	main()
{
	char *s = ft_substr("tripouille", 100, 1);
	
	if (s[0] == '\0')
		printf("null");
	printf("%c", s[0]);
}*/