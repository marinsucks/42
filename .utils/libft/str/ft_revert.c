/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:50:59 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:13:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

//reverts the order of the characters in a string
void	ft_revert_tab(char *s)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

//reverts the order of the characters in a number, but not the sign.
void	ft_revert_inttab(char *s)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(s) - 1;
	if (s[start] == '-')
		start++;
	while (start < end)
	{
		temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}
