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

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int     len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	range = malloc(sizeof(int) * len);
	if (!range)
		return(NULL);
	i = 0;
	while(i < len)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
/*
int	main(void)
{
	int	*range;
	int	i;

	range = ft_range(-5, 5);
	i = 0;
	while (i < 10)
	{
		printf("%d\n", range[i]);
		i++;
	}
	free(range);
	return (0);
}
*/
