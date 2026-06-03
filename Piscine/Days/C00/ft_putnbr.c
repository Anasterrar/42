#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if(nb >=0 && nb <= 9)
    {
        ft_putchar(nb + '0');
    }
        
    if(nb < 0)
    {
        ft_putchar('-');
        ft_putnbr(-1 * nb);
    }
    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    } 
}

int main(void)
{
    ft_putnbr(-125);
    write(1, "\n", 1);
    return 0;
}