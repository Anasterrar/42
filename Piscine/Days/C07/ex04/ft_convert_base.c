/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/15 01:04:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_valid_nbr(char *nbr, char *base);
int	ft_strlen(char *str);
int	is_valid_data(char *nbr, char *base_from, char *base_to);
int	is_valid_base(char *base);

int	get_sign(char *nbr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (nbr[i] == ' ' || nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

int	char_to_int(char *nbr, char *base_from)
{
	int	i;
	int	y;
	int	n;

	i = 0;
	n = 0;
	while (nbr[i] == ' ' || nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		y = 0;
		while (base_from[y])
		{
			if (base_from[y] == nbr[i])
				n = (n * (ft_strlen(base_from))) + y;
			y++;
		}
		i++;
	}
	return (n * get_sign(nbr));
}

int	str_size(int nbr, char *base_to)
{
	int		i;
	int		len_base;
	char	n[50];

	len_base = ft_strlen(base_to);
	if (nbr < 0)
		nbr *= -1;
	i = 0;
	while (nbr != 0)
	{
		n[i] = base_to[(nbr % len_base)];
		nbr /= len_base;
		i++;
	}
	n[i] = '\0';
	return (ft_strlen(n));
}

int	memory_size(int nn, char *base_to)
{
	int	size;

	size = sizeof(char) * str_size(nn, base_to) + 1;
	if (nn < 0)
		size += 1;
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		nn;
	char	*n;

	if (is_valid_data(nbr, base_from, base_to) == 0)
		return (NULL);
	nn = char_to_int(nbr, base_from);
	n = malloc(memory_size(nn, base_to));
	i = memory_size(nn, base_to) - 1;
	if (nn < 0)
		nn *= -1;
	n[i] = '\0';
	i--;
	while (i >= 0)
	{
		n[i] = base_to[(nn % ft_strlen(base_to))];
		nn /= ft_strlen(base_to);
		i--;
	}
	if (get_sign(nbr) == -1)
		n[0] = '-';
	return (n);
}
/*
int	main(void)
{
	char	*nbr = malloc(100);
	char	*choice1 = malloc(100);
	char	*choice2 = malloc(100);
	char	**bases = malloc(40);
	
	bases[0] = "01";
	bases[1] = "poneyvif";
	bases[2] = "0123456789";
	bases[3] = "0123456789abcdef";
	bases[4] = "abcdefghijklmnopqrstuvwxyz";
	
	// Choix
	printf("Entrez le nombre à convertir:\n");
	scanf("%s", nbr);
	printf("Choissez la base du nombre:\n");
	printf("\n1.Binaire\n2.Poneyvif\n3.Decimale\n4.Hexadecimale\n5.Alphabetique\n6.Personalisé\n");
	scanf("%s", choice1);
	printf("Choissez la base de conversion:\n");
	printf("\n1.Binaire\n2.Poneyvif\n3.Decimale\n4.Hexadecimale\n5.Alphabetique\n6.Personalisé\n");
	scanf("%s", choice2);
	//
	printf("%s\n", ft_convert_base(nbr, bases[atoi(choice1) - 1], bases[atoi(choice2) - 1]));
	return (0);
}
*/