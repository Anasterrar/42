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

#ifndef FT_DO_OP_H
#define FT_DO_OP_H
// INCLUDES LIB
#include <unistd.h>
#include <stdio.h>
// GLOBAL VARIABLE
#define ERROR_DIV_BY_0 "Stop : division by zero\n"
#define ERROR_MOD_BY_0 "Stop : modulo by zero\n"
//----FUNCTION
//STR
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
//NBR
void	ft_putnbr(int nbr);
int	ft_atoi(char *nbr);
//OPERATION
int	add(int a, int b);
int	sub(int a, int b);
int	divid(int a, int b);
int	mult(int a, int b);
int	mod(int a, int b);
//FT_DO_OP
void	ft_do_op(char **argv);
int	op(int a, int b, int(*f)(int, int));
//ERROR
int	is_errors(int argc, char **argv);
int	is_sign(char *sign);
#endif
