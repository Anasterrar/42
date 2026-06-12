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

int	ft_fibonacci(int index)
{
	int	n;
	if (index == 0)
		return (0);
	if (index < 0)
		return (-1);
	if (index ==1)
		return (1);
	n = (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (n);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_fibonacci(atoi(argv[1])));
	return (9);
}
*/
