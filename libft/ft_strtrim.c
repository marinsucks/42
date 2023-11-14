/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:45 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/14 17:15:52 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end - 1], set))
		end--;
							size_t len = end - start + 1;//quand uniquement des char de set, bizarrerie  
							printf("\n%zu\n", len); // checker si tte la string est set
	res = (char *)malloc(end - start + 1);
	if (!res)
		return (NULL);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = 0;
	return (res);
}

#include <stdio.h>

int	main(void)
{
	
	char *x = ft_strtrim("   xxx   xxx", " x");
	printf("%s\n", x);
	char*	set[] = {"abc", ""};
    char*	c[] = {
        "bcaXXXXabc",
        "abcXXXabcX",
        "",
        "a",
        "aX",
        "Xa",
        "aXc"
    };

	for (int j = 0; j < 2; j++)
	{
		printf("\nset: \t%s\n", set[j]);
		for (int i = 0; i < 7; i++)
			printf("Input: \t%s\nResult:\t%s\n", c[i], ft_strtrim(c[i], set[j]));
	}

}
