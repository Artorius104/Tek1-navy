/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** display_map.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void display_my_map(void)
{
    my_putstr("my positions :\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int x = 0, n = 1; x < 8; x++, n++) {
        my_put_nbr(n);
        my_putchar('|');
        for (int y = 0; y < 8; y++) {
            my_putchar(nav->map_p1[x][y]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

void display_enemy_map(void)
{
    my_putstr("enemy's positions :\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int x = 0, n = 1; x < 8; x++, n++) {
        my_put_nbr(n);
        my_putchar('|');
        for (int y = 0; y < 8; y++) {
            my_putchar(nav->map_p2[x][y]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}