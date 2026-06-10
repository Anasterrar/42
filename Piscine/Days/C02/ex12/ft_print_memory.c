/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 02:55:29 by marvin            #+#    #+#             */
/*   Updated: 2026/06/06 02:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str, int i)
{
	int	y;

	y = i;
	while (y < i + 16 && str[y] != '\0')
	{
		if (str[y] < 32 || str[y] == 127)
			write(1, ".", 1);
		else
			write(1, &str[y], 1);
		y++;
	}
}

void	ft_put_hexa_str(char *str, int i, int size)
{
	int	y;
	char	*hexa;

	y = i;
	hexa = "0123456789abcdef";
	while (y < i + 16)
	{
		if (y < size)
		{
			if (y % 2 == 0 && y > i)
				write(1, " ", 1);
			write(1, &hexa[str[y] / 16], 1);
			write(1, &hexa[str[y] % 16], 1);
		}
		else
			write(1, " ", 1);
		y++;
	}
}

void	print_addr(unsigned long addr)
{
	int	i;
	char	*hexa;
	char	hexa_addr[17];

	i = 15;
	hexa = "0123456789abcdef";
	hexa_addr[16] = '\0';
	while (i >= 0)
	{
		hexa_addr[i] = hexa[addr % 16];
		addr /= 16;
		i--;
	}
	ft_putstr(hexa_addr, 0);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) addr;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		if (i % 16 == 0)
		{
			print_addr((unsigned long)&((char *)addr)[i]);
			write(1, " ", 1);
			ft_put_hexa_str(str, i, size);
			write(1, " ", 1);
			ft_putstr(str, i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (addr);
}

int	main(void)
{
    char    str1[] = "Bonjour les aminches...c est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
    ft_print_memory(str1, 90);
    write(1, "\n", 1);
	return (0);
}
