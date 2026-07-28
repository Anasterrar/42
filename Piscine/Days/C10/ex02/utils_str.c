/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/26 23:54:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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

void	ft_put_header(char *file_name, int file_nbr)
{
	if (file_nbr > 1)
	{
		ft_putstr_fd("==> ", 1);
		ft_putstr_fd(file_name, 1);
		ft_putstr_fd(" <==\n", 1);
	}
}

void	ft_put_last_str(char *str, int n, int file_nbr, int file_read)
{
	int	i;

	if (n <= ft_strlen(str))
		i = ft_strlen(str) - n;
	else
		i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (file_read < file_nbr - 1)
		ft_putchar_fd('\n', 1);
}
