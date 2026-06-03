#include <unistd.h>
#include <stdio.h>

void ft_print(char i, char j, char y){
    write(1, &i, 1);
    write(1, &j, 1);
    write(1, &y, 1);
    if (!(i == '7' && j == '8' && y == '9'))
        write(1, ", ", 2);
    else
        write(1, "\n", 1);
}

void ft_print_comb(void){
    int i;
    int j;
    int y;
    i = 0;
    while (i <= 7)
    {
        j = i + 1;
        while (j <= 8)
        {
            y = j + 1;
            while(y <= 9)
            {
                ft_print(i + '0', j + '0', y + '0');
                y++;
            }
            j++;
        }
        i++;
    }
}

int main(void){
    ft_print_comb();
    return(0);
}