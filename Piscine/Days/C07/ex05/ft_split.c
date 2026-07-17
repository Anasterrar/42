/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/07/16 22:15:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
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
	while (i < index + ft_strlen(charset))
	{
		if (str[i] != charset[y])
			return (0);
		i++;
		y++;
	}
	return (1);
}

int	malloc_size_tab(char *str, char *charset, char ***tab)
{
	int	i;
	int	word_nbr;

	i = 0;
	word_nbr = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i) == 0)
		{
			word_nbr += 1;
			while (is_charset(str, charset, i) == 0)
				i++;
		}
		if (is_charset(str, charset, i) == 1)
			i += ft_strlen(charset);
	}
	*tab = malloc(sizeof(char *) * (word_nbr + 1));
	if (!(*tab))
		return (0);
	return (1);
}

int	copy_word(char *src, char **dest, int *i, int j)
{
	int	x;

	(*dest) = malloc(sizeof(char) * ((j - *i) + 1));
	if (!(*dest))
		return (0);
	x = 0;
	while (*i < j && src[*i])
	{
		(*dest)[x] = src[*i];
		(*i)++;
		x++;
	}
	(*dest)[x] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		y;
	int		j;
	char	**tab;

	if (malloc_size_tab(str, charset, &tab) == 0)
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i) == 0)
		{
			j = i;
			while (is_charset(str, charset, j) == 0 && str[j])
				j++;
			if (copy_word(str, &tab[y], &i, j) == 0)
				return (NULL);
			y++;
		}
		if (is_charset(str, charset, i) == 1)
			i += ft_strlen(charset);
	}
	tab[y] = 0;
	return (tab);
}
/*
void    ft_print_tab(char **tab, int size)
{
        int     i;

        i = 0;
        while (i < size)
        {
                printf("Tab: %d\n", i);
                printf("%s\n", tab[i]);
                i++;
        }
}

int	main(int argc, char **argv)
{
	int	i;
	char    *str;

	str = "Hello world !";
	printf("%s\n", str);
	i = 0;
	ft_print_tab(ft_split(str, " "), 3);
	return (0);
}
*/
