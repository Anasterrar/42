/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/29 18:34:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	is_sign(char *sign)
{
	int		i;
	char	*signs;

	i = 0;
	signs = "+-*/%";
	while (signs[i])
	{
		if (signs[i] == sign[0])
			return (1);
		i++;
	}
	return (0);
}

int	is_errors(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (is_sign(argv[2]) == 0)
	{
		ft_putstr_fd("0\n", 1);
		return (1);
	}
	if (ft_atoi(argv[3]) == 0)
	{
		if (argv[2][0] == '/')
		{
			ft_putstr_fd(ERROR_DIV_BY_0, 2);
			return (1);
		}
		if (argv[2][0] == '%')
		{
			ft_putstr_fd(ERROR_MOD_BY_0, 2);
			return (1);
		}
	}
	return (0);
}
