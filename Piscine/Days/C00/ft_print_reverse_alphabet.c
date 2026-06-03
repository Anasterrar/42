#include <unistd.h>

void ft_print_reverse_alphabet(void){
    write(1, "zyxwvutsrqponmlkjihgfedcba", 26);
}

void ft_print_reverse_alphabet2(void){
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while(alphabet[i] != '\0'){
        i++;
    };
    
    while(i >= 0){
        write(1, &alphabet[i], 1);
        i--;
    };
}

int main(void){
    ft_print_reverse_alphabet();
    write(1, "\n", 1);
    ft_print_reverse_alphabet2();
    return (0);
}