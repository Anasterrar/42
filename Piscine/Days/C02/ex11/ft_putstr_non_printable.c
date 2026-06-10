/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/06 02:09:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	i;
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{

			write(1, "\\", 1);
			write(1, &(hexa[str[i] / 16]), 1);
			write(1, &(hexa[str[i] % 16]), 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
