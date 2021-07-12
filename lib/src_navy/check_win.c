/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** check_win.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void end_message(int res)
{
    if (res == 1)
        my_putstr("I won\n");
    else
        my_putstr("Enemy won\n");
}

int check_enemy_win(void)
{
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nav->map_p1[i][j] == 'x')
                count++;
        }
    }
    if (count == 14)
        return 1;
    else
        return 0;
}

int check_my_win(void)
{
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nav->map_p2[i][j] == 'x')
                count++;
        }
    }
    if (count == 14)
        return 1;
    else
        return 0;
}