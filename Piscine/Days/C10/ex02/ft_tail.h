/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/26 23:58:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
#define FT_TAIL_H

//GLOBAL VARIABLE
#define BUFF_SIZE 10000

//INCLUDES
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include <stdio.h>

//-----FUNCTION
//-UTILS
//PRINT
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void    ft_put_last_str(char *str, int n, int file_nbr, int file_read);
void	ft_put_header(char *file_name, int file_nbr);	
//INT
int	char_to_int(char *str);
int     is_num(char *str);
int     ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
//ERROR
void    error_file(char *error_message, char *file_name);
void    error_invalid_c(char *invalid_arg);
void    error_non_arg(void);
//FT_TAIL
void	ft_tail_(int argc, char **argv);
void	read_file(char *file_name, int c, int file_nbr, int *file_read);
int	find_c(int argc, char **argv);

#endif
