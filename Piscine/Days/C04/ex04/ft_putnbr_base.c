/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/11 23:19:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	len_base;
	int	i;
	int	y;

	len_base = ft_strlen(base);
	i = 0;
	if (len_base <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		y = i + 1;
		while (base[y])
		{
			if (base[y] == base[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;

	if (is_valid_base(base) == 0)
		return ;
	base_len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n < base_len)
		write(1, &base[n], 1);
	else
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_base(atoi(argv[1]), "0123456789abcdef");
	write(1, "\n", 1);
	return (0);
}
*/
