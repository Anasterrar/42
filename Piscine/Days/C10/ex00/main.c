/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/23 23:28:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (0);
	}
	if (argc > 2)
        {
                ft_putstr_fd("Too many arguments.\n", 2);
                return (0);
        }
	ft_display_file(argv[1]);
	return (0);
}
