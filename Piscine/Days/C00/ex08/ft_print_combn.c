#include <unistd.h>
#include <stdlib.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int*num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + '0');
		i++;
	}
	if (num[0] == (10 - n) && num[n - 1] == 9)
		return ;
	ft_putchar(',');
	ft_putchar(' ');
}

void	setup(int*num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	if (n == 1)
		ft_print(num, n);
}

void	ft_print_combn(int n)
{
	int	i;
	int	num[10];

	setup(num, n);
	i = n - 1;
	if (n > 0 && n < 10)
	{
		while (num[0] <= (10 - n) && num[n - 1] <= 9)
		{
			if (i == n - 1)
			{
				num[i] = num[i - 1] + 1;
				while (num[i] <= 9)
				{
					ft_print(num, n);
					num[i]++;
				}
			}
			if (i > 0)
				num[i] = num[i - 1] + 1;
			else
				num[i]++;
			i = (i + 1) % n;
		}
	}
}

int	main()
{
	ft_print_combn(3);
	return (0);
}