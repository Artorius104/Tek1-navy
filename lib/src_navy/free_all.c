/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** free_all.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

void free_struct(void)
{
    free(nav->map_p1);
    free(nav->map_p2);
    free(nav);
}