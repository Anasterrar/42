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

#include "ft_tail.h"

void	error_file(char *file_name, char *error_message)
{
	ft_putstr_fd("ft_tail: cannot open '", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd("' for reading: ", 2);
	ft_putstr_fd(error_message, 2);
	ft_putchar_fd('\n', 2);
}

void	error_invalid_c(char *invalid_arg)
{
	ft_putstr_fd("ft_tail: invalid number of bytes: '", 2);
	ft_putstr_fd(invalid_arg, 2);
	ft_putstr_fd("'\n", 2);
}

void	error_non_arg(void)
{
	ft_putstr_fd("ft_tail: option requires an argument -- 'c'\n", 2);
}
