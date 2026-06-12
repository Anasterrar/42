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

#include <stdlib.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	n;

	if (nb < 0)
		return (0);
	i = 1;
	n = i;
	while (i <= nb)
	{
		n *= i;
		i++;
	}
	return (n);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_iterative_factorial(atoi(argv[1])));
	return (0);
}
*/
