/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/24 02:18:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_display_file(char *file_name)  
{
	int	fd;
	ssize_t	numRead;
	char	buff[BUFF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return ;
	}
	numRead = read(fd, buff, BUFF_SIZE - 1);
	while (numRead > 0)
	{
		buff[numRead] = '\0';
		ft_putstr_fd(buff, 1);
		numRead = read(fd, buff, BUFF_SIZE - 1);
	}
	close(fd);
}
