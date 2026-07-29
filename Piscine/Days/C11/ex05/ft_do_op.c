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

#include "ft_do_op.h"

int	op(int a, int b, int(*f)(int, int))
{
	return (f(a, b));
}

void	ft_do_op(char **argv)
{
	int	(*f)(int, int);
	int	result;

	if (argv[2][0] == '+')
		f = add;
	if (argv[2][0] == '-')
		f = sub;
	if (argv[2][0] == '/')
		f = divid;
	if (argv[2][0] == '*')
		f = mult;
	if (argv[2][0] == '%')
		f = mod;
	result = op(ft_atoi(argv[1]), ft_atoi(argv[3]), f);
	ft_putnbr(result);
	ft_putchar_fd('\n', 1);
}
