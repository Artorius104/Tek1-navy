/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** readme.c
*/

#include "../../include/navy.h"

void readme(void)
{
    write(1, "USAGE\n", 7);
    write(1, "     ./navy [first_player_pid] navy_positions\n", 47);
    write(1, "DESCRIPTION\n", 13);
    write(1, "     first_player_pid: only for the ", 37);
    write(1, "2nd player. pid of the first player.\n", 38);
    write(1, "     navy_positions: file representing the ", 44);
    write(1, "positions of the ships.\n", 25);
}