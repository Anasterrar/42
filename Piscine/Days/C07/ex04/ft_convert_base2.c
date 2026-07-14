/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/15 01:00:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		y = i + 1;
		while (base[i] && base[y])
		{
			if (base[i] == base[y])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	is_valid_nbr(char *nbr, char *base)
{
	int	i;
	int	y;
	int	in_base;

	i = 0;
	while (nbr[i])
	{
		y = 0;
		in_base = 0;
		while (base[y])
		{
			if (nbr[i] == base[y] || nbr[i] == ' '
				|| nbr[i] == '-' || nbr[i] == '+')
				in_base = 1;
			y++;
		}
		if (in_base == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_data(char *nbr, char *base_from, char *base_to)
{
	if (is_valid_nbr(nbr, base_from) == 0)
		return (0);
	if (is_valid_base(base_from) == 0)
		return (0);
	if (is_valid_base(base_to) == 0)
		return (0);
	return (1);
}
