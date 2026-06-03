/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 01:04:32 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 01:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void    ft_print(int i, int j)
{
    char i1 = (i / 10) + '0';
    char i2 = (i % 10) + '0';
    char j1 = (j / 10) + '0';
    char j2 = (j % 10) + '0';
    write(1, &i1, 1);
    write(1, &i2, 1);
    write(1, " ", 1);
    write(1, &j1, 1);
    write(1, &j2, 1);
    if(i == 98 && j == 99)
        write(1, "\n", 1);
    else
        write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
    int i;
    int j;

    i = 0;
    while(i <= 98)
    {
        j = i;
        while(j <= 99)
        {   
            if(i != j)
                ft_print(i, j);
            j++;
        }
        i++;
    }
}

int	main(void)
{
    ft_print_comb2();
    return 0;
}
