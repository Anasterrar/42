/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/23 21:16:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_charset(char *str, char *charset, int index)
{
	int	i;
	int	y;

	i = index;
	y = 0;
	while (charset[y] && str[i])
	{
		if (charset[y] != str[i])
			return (0);
		i++;
		y++;
	}
	return (1);
}

//compter les mots
int	malloc_size(char ***tab, char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i) == 0)
		{
			size += 1;
			while (is_charset(str, charset, i) == 0 && str[i])
				i++;
		}
		if (is_charset(str, charset, i) == 1 && str[i])
			i++;
	}
	(*tab) = malloc(sizeof(char *) * (size + 1));
	if (!(*tab))
		return (0);
	return (1);
}

int	copy_word(char **tab, char *str, int *index, int j)
{
	int	i;

	i = 0;
	*tab = malloc(sizeof(char) * (j - (*index) + 1));
	if (!(*tab))
		return (0);
	while ((*index) < j)
	{
		(*tab)[i] = str[*index];
		i++;
		(*index)++;
	}
	(*tab)[i] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		y;
	int		j;

	if (malloc_size(&tab, str, charset) == 0)
		return (0);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i) == 0)
		{
			j = i;
			while (is_charset(str, charset, j) == 0 && str[j])
				j++;
			if (copy_word(&tab[y], str, &i, j) == 0)
				return (0);
			y++;
		}
		if (is_charset(str, charset, i) == 1)
			i += ft_strlen(charset);
	}
	tab[y] = 0;
	return (tab);
}
/*
void	print_tab(char **tab)
{
	int	i;
	
	i = 0;
	while (tab[i] != 0)
	{
		printf("Tab[%d]:\n%s\n", i, tab[i]);
		i++;
	}
}

int	main(void)
{
	char *str;
	char *charset;

	str = "  Hello word !  ";
	charset = " ";
	char **tab = ft_split(str, charset);
	print_tab(tab);
	return (0);
}
*/
