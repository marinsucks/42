/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-gars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:32:04 by mle-gars          #+#    #+#             */
/*   Updated: 2023/07/02 15:32:12 by mle-gars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_lgn(int nbClm, char first, char inbtw, char last)
{
	ft_putchar(first);
	while (nbClm - 2 > 0)
	{
		ft_putchar(inbtw);
		--nbClm;
	}
	if (nbClm > 1)
		ft_putchar(last);
	ft_putchar ('\n');
}

void	ft_not_neg_not_min(int *colptr, int *ligptr)
{
	if (*colptr == -2147483648)
		*colptr = 2147483647;
	if (*ligptr == -2147483648)
		*ligptr = 2147483647;
	if (*colptr < 0)
		*colptr = *colptr * -1;
	if (*ligptr < 0)
		*ligptr = *ligptr * -1;
}

void	rush(int x, int y)
{
	ft_not_neg_not_min(&x, &y);
	if (y > 0 && x > 0)
	{
		ft_print_lgn(x, 'A', 'B', 'A');
		while (y - 2 > 0)
		{
			ft_print_lgn(x, 'B', ' ', 'B');
			--y;
		}
		if (y > 1)
			ft_print_lgn(x, 'C', 'B', 'C');
	}
}
