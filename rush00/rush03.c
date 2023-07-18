/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-gars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:32:28 by mle-gars          #+#    #+#             */
/*   Updated: 2023/07/02 15:32:43 by mle-gars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	return_line(char charactere)
{
	if (charactere == 'A')
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	if (charactere == 'B')
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
	if (charactere == 'C')
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
}

void	printcolumn_abc(int colb)
{
	int	jb;

	jb = 0;
	while (jb < colb)
	{
		if (jb == 0 && jb == colb - 1)
		{
			return_line('A');
		}
		else
		{
			if (jb == 0)
			{
				ft_putchar('A');
			}
			else if (jb == colb - 1)
			{
				return_line('C');
			}
			if (jb != 0 && jb != colb - 1)
				ft_putchar('B');
		}
		jb++;
	}
}

void	printcolumn_bb(int colb)
{
	int	jb;

	jb = 0;
	while (jb < colb)
	{
		if (jb == 0 && jb == colb - 1)
		{
			return_line('B');
		}
		else
		{
			if (jb == 0)
				ft_putchar('B');
			if (jb == colb - 1)
				return_line('B');
			if (jb != 0 && jb != colb - 1)
				ft_putchar(' ');
		}
		jb++;
	}
}

void	not_neg_not_min(int *colptr, int *ligptr)
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
	int	i;

	i = 0;
	not_neg_not_min(&x, &y);
	while (i < y) //lignes > 0
	{
		if (i == 0 || i == y - 1) //si lignes = 1 ou 2
		{
			printcolumn_abc(x);
		}
		if (i != 0 && i != y - 1)
		{
			printcolumn_bb(x);
		}
		i++;
	}
}
