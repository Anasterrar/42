/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/05 02:27:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab, int size)
{
	for(int i = 0; i < size; i++)
		ft_putchar(tab[i] + '0');
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

int	main(void)
{
	int	size = 5;
	int	tab[size];

	for(int i = 0; i < size; i++)
		tab[i] = i + 1;
	print_tab(tab, size);
	ft_putchar('\n');
	ft_rev_int_tab(tab, size);
	print_tab(tab, size);
	ft_putchar('\n');
	return (0);
}
