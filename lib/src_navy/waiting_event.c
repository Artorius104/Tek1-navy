/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** waiting_event.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

int hit_management(int y, int x)
{
    if (nav->map_p1[x][y] != '.') {
        nav->map_p1[x][y] = 'x';
        return 1;
    } else {
        nav->map_p1[x][y] = 'o';
        return 0;
    }
}

int receive_attack(int signal)
{
    int nb = 0;

    pause();
    usleep(100);
    for (int i = 1; i != 0 ; i = usleep(100000), usleep(100)) {
        kill(nav->pid_p1, signal);
        nb++;
    }
    return nb;
}

void waiting_for_attack(int signal)
{
    int x = 0;
    int y = 0;
    int check = 0;

    my_putstr("waiting for enemy’s attack...\n");
    x = receive_attack(signal);
    kill(nav->pid_p1, signal);
    y = receive_attack(signal);
    check = hit_management(x - 1, y - 1);
    my_putchar(x + 'A' - 1);
    my_put_nbr(y);
    my_putstr(": ");
    if (check == 1) {
        my_putstr("hit\n\n");
        send_attack(1, signal);
    } else {
        my_putstr("missed\n\n");
        send_attack(2, signal);
    }
}