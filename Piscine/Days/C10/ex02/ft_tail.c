/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/27 01:01:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	file_nbr(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
			i += 2;
		else
		{
			n++;
			i++;
		}
	}
	return (n);
}

int	find_c(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			if ((i + 1) < argc)
			{
				if (is_num(argv[i + 1]) == 1)
					return (char_to_int(argv[i + 1]));
				error_invalid_c(argv[i + 1]);
				return (-1);
			}
			error_non_arg();
			return (-1);
		}
		i++;
	}
	return (10);
}

void	read_file(char *file_name, int c, int file_nbr, int *file_read)
{
	int		fd;
	ssize_t	num_read;
	char	buff[BUFF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		num_read = read(fd, buff, BUFF_SIZE - 1);
		while (num_read > 0)
		{
			buff[num_read] = '\0';
			num_read = read(fd, buff, BUFF_SIZE - 1);
		}
		ft_put_header(basename(file_name), file_nbr);
		ft_put_last_str(buff, c, file_nbr, *file_read);
		(*file_read)++;
	}
	else
	{
		error_file(basename(file_name), strerror(errno));
		return ;
	}
	close(fd);
}

void	ft_tail_(int argc, char **argv)
{
	int	i;
	int	c;
	int	file_n;
	int	file_read;

	c = find_c(argc, argv);
	if (c == -1)
		return ;
	file_n = file_nbr(argc, argv);
	file_read = 0;
	i = 1;
	if (ft_strcmp(argv[i], "-c") == 0)
		i += 2;
	while (i <= argc - 1)
	{
		if (ft_strcmp(argv[i], "-c") != 0)
		{
			read_file(argv[i], c, file_n, &file_read);
			i++;
		}
		else
			i += 2;
	}
}
