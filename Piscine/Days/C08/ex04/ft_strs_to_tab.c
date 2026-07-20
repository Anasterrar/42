/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/20 23:15:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include "ft_stock_str.h"
/*
typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}	t_stock_str;
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_all(t_stock_str **tab, int i)
{
	int	y;

	y = 0;
	while (y < i)
	{
		free((*tab)[y].copy);
		y++;
	}
	free(*tab);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(tab[i].str);
		if (!tab[i].copy)
		{
			free_all(&tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
/*
int	main()
{
	char	**tab;

	tab = malloc(sizeof(char *) * 5);
	for(int	i; i < 4; i++)
		tab[i] = malloc(10);
	tab[0] = "12345";
	tab[1] = "12345678910";
	tab[2] = "";
	tab[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	struct s_stock_str *tab2 = ft_strs_to_tab(4, tab);
	ft_show_tab(tab2);
	write(1, "\n", 1);
	int	i = 3;
	return (0);
}
*/