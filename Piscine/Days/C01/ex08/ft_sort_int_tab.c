/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ------ <------@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/04 20:48:58 by ------           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab, int size)
{
	for(int i = 0; i < size; i++)
		ft_putchar(tab[i] + '0');
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	y;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (i < size - 1)
			y = i + 1;
		while (y < size)
		{
			tmp = tab[i];
			if (tab[i] > tab[y])
			{
				tab[i] = tab[y];
				tab[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

int	main(void)
{
	int	size = 1;
	int	tab[size];

	tab[0] = 5;
	print_tab(tab, size);
	ft_putchar('\n');
	ft_sort_int_tab(tab, size);
	print_tab(tab, size);
	ft_putchar('\n');
	return (0);
}
