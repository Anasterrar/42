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

#include "ft_hexdump.h"

int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}


int	ft_atoi(char *str_nbr)
{
	int	i;
	int	nbr;
	
	i = 0;
	nbr = 0;
	while (str_nbr[i])
	{
		nbr = nbr * 10 + (str_nbr[i] - '0');
		
		i++;
	}
	return (nbr);
}

int	str_size(int nbr)
{
	int	i;
	char	buff[50];
	char	*hexa;

	i = 0;
	hexa = "0123456789abcdef";
	while (nbr != 0)
	{
		buff[i] = hexa[nbr % 16];
		nbr /= 16;
		i++;
	}
	buff[i] = '\0';
	return (ft_strlen(buff));
}

char	*int_to_hex(int nbr)
{
	int	i;
	int	size;
	char	*hexadecimal;
	char	*buff;
	
	size = str_size(nbr);
	i = size;
	hexadecimal = "0123456789abcdef";
	buff = malloc(sizeof(char) * (size + 1));
	buff[i] = '\0';
	i--;
	while (i >= 0)
	{
		buff[i] = hexadecimal[nbr % 16];
		nbr /= 16;
		i--;
	}
	return (buff);
}
