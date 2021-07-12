/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** player_two.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void connection_player_two(char **av)
{
    nav->pid_p1 = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(nav->pid_p1);
    my_putchar('\n');
    nav->pid_p2 = my_getnbr(av[1]);
    kill(nav->pid_p2, SIGUSR2);
    pause();
    my_putstr("successfully connected\n\n");
}

int player_two(int ac, char **av, struct sigaction p2)
{
    connection_player_two(av);
    fill_map(ac, av);
    while (check_my_win() != 1 && check_enemy_win() != 1) {
        display_my_map();
        display_enemy_map();
        waiting_for_attack(SIGUSR1);
        attack(SIGUSR1);
    }
    if (check_my_win() == 1)
        return 1;
    else
        return 0;
}