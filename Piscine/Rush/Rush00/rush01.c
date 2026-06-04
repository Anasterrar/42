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
                // slash
                if((h == 0 && l == 0) || (h == y - 1 && l == x - 1 && h > 1 && l > 1))
                    ft_putchar(47);
                // anti-slash
                if((h == 0 && l == x - 1 && x > 1) || (h == y - 1 && y > 1 && l == 0 ))
                    ft_putchar(92);
                if(x > 1 && l > 0 && l < x -1)
                    ft_putchar('*');
            }
            else
            {
                if(l == 0 || l == x - 1)
                    ft_putchar('*');
                else
                    ft_putchar(' ');
            }
        }
        ft_putchar('\n');
    }
}