/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/12 01:02:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	conv_nb(char *nb, int sign)
{
	int	i;
	int	n;
	int	f;

	i = 0;
	n = 0;
	f = 1;
	while (nb[i])
		i++;
	i--;
	while (i >= 0)
	{
		n += ((nb[i] - '0') *f);
		f *= 10;
		i--;
	}
	return (n * sign);
}

int	ft_atoi(char *nb)
{
	int		i;
	int		y;
	int		sign;
	char	n[20];

	i = 0;
	y = 0;
	sign = 1;
	while (nb[i] == ' ')
		i++;
	while (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		n[y] = nb[i];
		i++;
		y++;
	}
	n[y] = '\0';
	return (conv_nb(n, sign));
}
/*
int	main(void)
{
	char	str[] = " ---+--+1234ab567";
	printf("Str => %s\n", str);
	printf("Atoi => %d\n", atoi(str));
	printf("ft_atoi => %d\n", ft_atoi(str));
	return (0);
}
*/