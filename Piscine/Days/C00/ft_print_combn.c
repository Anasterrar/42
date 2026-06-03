#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char * str)
{
    for (int i = 0; str[i] != '\0'; i++)
        ft_putchar(str[i]);
}

void ft_print(int * num, int n)
{
    int first[n];
    for (int i = 0; i <= n - 1; i++)
    {
        first[i] = i;
    }

    
    for (int i = 0; i < n; i++)
        ft_putchar(num[i] + '0');
    
}

void  is_valid(int num, int n)
{
    int nums[n];
    int d = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        nums[i] = (num / d) % 10;
        d = d * 10;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(nums[i] >= nums[i + 1])
            return;
    }
    int first[n];
    for (int i = 0; i < n; i++)
    {
        first[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if(nums[i] != first[i])
        {
            ft_putstr(", ");
            break;
        }
            
    }
    ft_print(nums, n);
}

void ft_print_combn(int n)
{
    int num;
    int max = 1;
    for (int i = n - 1; i > 0; i--)
    {
        max = max * 10;
    }
    max = max * 10;
    while(num < max)
    {
        is_valid(num, n);
        num++;
    }
}

int main(void)
{
    ft_print_combn(2);
    ft_putchar('\n');
    return 0;
}