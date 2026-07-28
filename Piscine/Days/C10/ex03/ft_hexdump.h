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

#ifndef FT_HEXDUMP_H
#define FT_HEXDUMP_H
//GLOBAL VARIABLE
#define BUFF_SIZE 17
#define BUFF_HEX_SIZE 33
#define ERROR_P_NAME "ft_hexdump: "
#define ERROR_MISSING_FILE ": No such file or directory\n"
#define ERROR_ALL_FILE "ft_hexdump: all input file arguments failed\n"
//INCLUDES
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>
//---UNCTIONS
//HEX
int	ft_strlen(char *str);
int	nbr_len(int nbr);
int	ft_atoi(char *str_nbr);
char	*int_to_hex(int nbr);
// FT_HEXDUMP
void	ft_hexdump(int argc, char **argv);
void	read_file(char *file_name, int *oct_read);
void	print_offset(char *offset, int is_first);
void	print_oct(char *str);
// STRING
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
// ERROR
void    is_file(char *file, int *errors);
int     is_error(int argc, char **argv);
void    error_missing_file(char *filename);
void    error_all_file_missging(void);
#endif
