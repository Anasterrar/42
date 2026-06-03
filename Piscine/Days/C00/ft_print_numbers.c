#include <unistd.h>

void ft_print_numbers(void){
    write(1, "0123456789", 10);
}

void ft_print_numbers2(void){
    int i = 0;
    char c;
    while(i < 10){
        c = i + '0';
        write(1, &c, 1);
        i++;
    };
}

int main(void){
    ft_print_numbers();
    write(1, "\n", 1);
    ft_print_numbers2();
    return (0);
}