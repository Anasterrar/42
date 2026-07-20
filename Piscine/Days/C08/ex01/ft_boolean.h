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

#ifndef FT_BOOLEAN_H

#define FT_BOOLEAN_H

#include <unistd.h>

#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define EVEN(nbr) (((nbr) % 2) == 0)

typedef int t_bool;

void	ft_putstr(char *str);

#endif
