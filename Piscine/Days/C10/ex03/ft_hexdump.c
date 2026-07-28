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

void	print_offset(char *offset, int is_first)
{
	int	i;

	i = 0;
	if (is_first == 0)
		ft_putchar_fd('\n', 1);
	while (i < 7 - ft_strlen(offset))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	ft_putstr_fd(offset, 1);
}

void	print_oct(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if(i < len)
			ft_putstr_fd("   ", 1);
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	read_file(char	*file_name, int	*oct_read)
{
	int	fd;
	ssize_t	num_read;
	char	buff[BUFF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		num_read = read(fd, buff, BUFF_SIZE - 1 - (*oct_read % 16));
		while (num_read > 0)
		{
			buff[num_read] = '\0';
			if (*oct_read % 16 == 0)
				print_offset(int_to_hex(*oct_read), (*oct_read == 0));
			print_oct(buff);
			(*oct_read) += num_read;
			num_read = read(fd, buff, BUFF_SIZE - 1 - (*oct_read % 16));
		}
	}
	else
	{
		//error
		return ;
	}
	close(fd);
}

void	ft_hexdump(int argc, char **argv)
{
	int	i;
	int	oct_read;

	i = 1;
	oct_read = 0;
	if (is_error(argc, argv) == 1)
		return ;
	while (i < argc)
	{
		read_file(argv[i], &oct_read);
		i++;
	}
	print_offset(int_to_hex(oct_read), (oct_read == 0));
	ft_putchar_fd('\n', 1);
}
