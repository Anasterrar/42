/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/14 18:21:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		len += (ft_strlen(sep) * (size - 1));
	return (len + 1);
}

void	ft_strcpy(int *index, char *str, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		str[(*index)] = src[i];
		(*index)++;
		i++;
	}
}

char	*error_empty(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;

	if (size <= 0)
		return (error_empty());
	str = malloc(sizeof(char) * total_len(size, strs, sep));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(&j, str, strs[i]);
		if (i < size - 1)
			ft_strcpy(&j, str, sep);
		i++;
	}
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*strs[] = {
		"Hello",
		"World",
		"and",
		"hello",
		"space",
		"!"
	};
	char	*sep;
	int	size;
	char	*str;
	
	sep = " ";
	size = 6;
	str = ft_strjoin(size, strs, sep);
	free(str);
	return (0);
}
*/