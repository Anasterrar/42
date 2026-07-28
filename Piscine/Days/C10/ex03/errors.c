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

void    is_file(char *file, int *errors)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
		close(fd);
	else
	{
		error_missing_file(basename(file));
		(*errors)++;
	}
}

int     is_error(int argc, char **argv)
{
	int	i;
	int	errors;

	i = 1;
	errors = 0;
	while (i < argc)
	{
		is_file(argv[i], &errors);
		i++;
	}
	if (errors == argc - 1)
	{
		error_all_file_missging();
		return (1);
	}
	else
		return (0);
		
}
void    error_missing_file(char *filename)
{
	ft_putstr_fd(ERROR_P_NAME, 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(ERROR_MISSING_FILEanas@DESKTOP-KJMLS7C:/mnt/c/Users/Anes/Documents/Project/C/42/Piscine/Days/C10/ex03$ hexdump -c 1.txt 2.txt 3 .txt 0000000 H e l l o W o r l d ! B L A 0000010 B L A B L A O O O O O O O \n 000001e anas@DESKTOP-KJMLS7C:/mnt/c/Users/Anes/Documents/Project/C/42/Piscine/Days/C10/ex03$ ./ft\\_hexdump -c 1.txt 2. txt 3.txt ft\\_hexdump: -c: No such file or directory 0000000 H e l l o W o r l d ! B L A 0000010 B L A B L A O O O O O O O 000001e, 2);
}
void    error_all_file_missging(void)
{
	ft_putstr_fd(ERROR_ALL_FILE, 2);
}
