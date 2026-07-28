/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/25 09:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_read_file(char *fileName)
{
	int		fd;
	ssize_t	num_read;
	char	buff[BUFF_SIZE];

	fd = open(fileName, O_RDONLY);
	if (fd != -1)
	{
		num_read = read(fd, buff, BUFF_SIZE - 1);
		while (num_read > 0)
		{
			buff[num_read] = '\0';
			ft_putstr_fd(buff, 1);
			num_read = read(fd, buff, BUFF_SIZE - 1);
		}
	}
	else
	{
		error(basename(fileName), strerror(errno));
		return ;
	}
	close(fd);
}

void	ft_cat(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_read_file(argv[i]);
		i++;
	}
}
