/*
** EPITECH PROJECT, 2020
** CPool_Day03_2020
** File description:
** my_isneg
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
