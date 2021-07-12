/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** interactions.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void send_attack(int nb, int signal)
{
    kill(nav->pid_p2, signal);
    for (int i = 0; i < nb; i++) {
        kill(nav->pid_p2, signal);
        pause();
        usleep(100);
    }
}

int attack(int signal)
{
    int check = 0;
    size_t s;
    char *pos = malloc(sizeof(char) * 2);

    my_putstr("attack: ");
    getline(&pos, &s, stdin);
    if (pos[0] < 'A' && pos[0] > 'H' && pos[1] < '0'
    && pos[1] > '8') {
        my_putstr("wrong position\n");
        return -1;
    }
    send_attack(pos[0] - 'A' + 1, signal);
    pause();
    usleep(100);
    send_attack(pos[1] - '1' + 1, signal);
    if (receive_attack(signal) == 1) {
        nav->map_p2[pos[1] - '1'][pos[0] - 'A'] = 'x';
        my_putchar(pos[0]);
        my_putchar(pos[1]);
        my_putstr(": ");
        my_putstr("hit\n\n");
    } else {
        nav->map_p2[pos[1] - '1'][pos[0] - 'A'] = 'o';
        my_putchar(pos[0]);
        my_putchar(pos[1]);
        my_putstr(": ");
        my_putstr("missed\n\n");
    }
}