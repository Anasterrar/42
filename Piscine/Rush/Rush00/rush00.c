#include "ft_putchar.c"
void ft_putchar(char c);

void rush(int x, int y)
{
    for (int h = 0; h < y; h++)
    {
        for (int l = 0; l < x; l++)
        {
            //Top and bottom
            if(h == 0 || h == y - 1)
            {
                //left and right, and middle
                if(l == 0 || l == x - 1)
                    ft_putchar('o');
                else
                    ft_putchar('-');
            }
            //on middle, left and right, and on middle
            else
            {
                if(l == 0 || l == x - 1)
                    ft_putchar('|');
                else
                    ft_putchar(' ');
            }
        }
        ft_putchar('\n');
    }
}