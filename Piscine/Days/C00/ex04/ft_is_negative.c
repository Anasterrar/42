#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

void ft_is_negative(int n){
    ft_putchar((n >= 0) ? 'P' : 'N');
}

int main(void){
    ft_is_negative(0);
    ft_is_negative(10);
    ft_is_negative(-5);
    return (0);
}