/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** player_one.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void connection_player_one(void)
{
    nav->pid_p1 = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(nav->pid_p1);
    my_putstr("\nwaiting for enemy connection...\n\n");
    pause();
    kill(nav->pid_p2, SIGUSR1);
    while (nav->turn == 0)
        usleep(1000);
    my_putstr("enemy connected\n\n");
}

int player_one(int ac, char **av, struct sigaction p1)
{
    connection_player_one();
    fill_map(ac, av);
    while (check_my_win() != 1 && check_enemy_win() != 1) {
        display_my_map();
        display_enemy_map();
        attack(SIGUSR1);
        waiting_for_attack(SIGUSR1);
    }
    if (check_my_win() == 1)
        return 1;
    else
        return 0;
}