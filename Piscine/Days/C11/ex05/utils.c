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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

int	ft_atoi(char *nbr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nbr[i] == ' ' || nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		n = n * 10;
		n += (nbr[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_putnbr(int nbr)
{
	if (nbr <= -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (nbr >= 2147483647)
	{
		ft_putstr_fd("2147483647", 1);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr(nbr * -1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar_fd(nbr + '0', 1);
}
