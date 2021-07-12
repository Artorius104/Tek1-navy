/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** init.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void init_global(void)
{
    nav = malloc(sizeof(navy_t));
    nav->turn = 0;
    nav->pid_p2 = 0;
    nav->pid_p1 = 0;
    nav->count = 0;
}

void init_sigaction(struct sigaction p1, struct sigaction p2)
{
    p1.sa_flags = SA_SIGINFO;
    p2.sa_flags = SA_SIGINFO;
    p1.sa_sigaction = &signal_handler;
    p2.sa_sigaction = &signal_handler;
    sigaction(SIGUSR1, &p1, NULL);
    sigaction(SIGUSR2, &p2, NULL);
}

void init_map(int ac, char **av)
{
    nav->map_p1 = malloc(sizeof(char *) * 8);
    nav->map_p2 = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        nav->map_p1[i] = malloc(sizeof(char) * 9);
        nav->map_p2[i] = malloc(sizeof(char) * 9);
    }
    for (int i = 0, j; i < 8; i++, j = 0) {
        for (j = 0; j < 8; j++) {
            nav->map_p1[i][j] = '.';
            nav->map_p2[i][j] = '.';
        }
        nav->map_p1[i][j] = '\n';
        nav->map_p2[i][j] = '\n';
    }
}