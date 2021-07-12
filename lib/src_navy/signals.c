/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** signals.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void signal_handler(int signum, siginfo_t *act, void *oldact)
{
    if (signum == SIGUSR1) {
        nav->turn = 1;
        nav->pid_p1 = act->si_pid;
    }
    if (signum == SIGUSR2) {
        nav->turn = 2;
        nav->pid_p2 = act->si_pid;
    }
}