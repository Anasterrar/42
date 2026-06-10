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
#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (dest[i])
		i++;
	while(dest[i] && src[y])
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[20] = "Hello ";
	char	src[6] = "World";

	printf("strcat => %s\n", strcat(dest, src));
	printf("ft_strcat => %s\n", ft_strcat(dest, src));
	return (0);
}
*/
