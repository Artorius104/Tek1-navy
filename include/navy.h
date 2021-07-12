/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** navy.h
*/

#ifndef NAVY_H
#define NAVY_H

#include "my.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>

typedef struct m_st
{
    char **map_p1;
    char **map_p2;
    int pid_p1;
    int pid_p2;
    int turn;
    int count;
} navy_t;

void readme(void);
void init_global(void);
void init_sigaction(struct sigaction p1, struct sigaction p2);
void init_map(int ac, char **av);
void free_struct(void);
int check_arg(int ac, char **av);
int check_file(int ac, char **av);
int check_read_file(int fd, int ac, char *filepath);
int check_file_content(char *buffer);
void signal_handler(int signum, siginfo_t *act, void *oldact);
int player_one(int ac, char **av, struct sigaction p1);
int player_two(int ac, char **av, struct sigaction p2);
void connection_player_one(void);
void connection_player_two(char **av);
void fill_map(int ac, char **av);
char *get_coordinates(int fd, char *filepath);
void place_my_ships(char *buffer);
void place_ship(int size, char *start, char *end);
int get_x(char *coord);
void display_my_map(void);
void display_enemy_map(void);
int attack(int signal);
char *read_attack(void);
void send_attack(int nb, int signal);
void waiting_for_attack(int signal);
int receive_attack(int signal);
int hit_management(int x, int y);
int check_my_win(void);
int check_enemy_win(void);
void end_message(int res);

#endif