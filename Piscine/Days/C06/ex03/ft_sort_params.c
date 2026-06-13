/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/13 06:40:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_params(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

int	is_sortable(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		y;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		if (i < argc - 1)
			y = i + 1;
		while (y < argc)
		{
			tmp = argv[i];
			if (is_sortable(argv[i], argv[y]) > 0)
			{
				argv[i] = argv[y];
				argv[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	print_params(argv);
	return (0);
}
