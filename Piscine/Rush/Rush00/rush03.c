#include "ft_putchar.c"
void ft_putchar(char c);

void rush(int x, int y)
{
    for (int h = 0; h < y; h++)
    {
        for (int l = 0; l < x; l++)
        {
            if ((h == 0) || (h == y - 1 && y > 1))
            { 
                // A
                if(l == 0)
                    ft_putchar('A');
                // C
                if(l == x - 1 && x > 1)
                    ft_putchar('C');
                if(x > 1 && l > 0 && l < x -1)
                    ft_putchar('B');
            }
            else
            {
                if(l == 0 || l == x - 1)
                    ft_putchar('B');
                else
                    ft_putchar(' ');
            }
        }
        ft_putchar('\n');
    }
}