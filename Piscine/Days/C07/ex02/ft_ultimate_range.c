/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/14 01:47:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min >= max)
	{
		(*range) = NULL;
		return (0);
	}
	len = max - min;
	*range = malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len);
}
/*
int	main(void)
{
	int	*range;
	int	**prange;
	int	i;

	prange = &range;
	ft_ultimate_range(prange, -5, 5);
	i = 0;
	while (i < 10)
	{
		printf("%d\n", (*prange)[i]);
		i++;
	}
	free(range);
	return (0);

}
*/
