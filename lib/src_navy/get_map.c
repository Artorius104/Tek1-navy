/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** init.c
*/

#include "../../include/navy.h"

extern navy_t *nav;

int get_x(char *coord)
{
    if (coord[0] == 'A')
        return 0;
    if (coord[0] == 'B')
        return 1;
    if (coord[0] == 'C')
        return 2;
    if (coord[0] == 'D')
        return 3;
    if (coord[0] == 'E')
        return 4;
    if (coord[0] == 'F')
        return 5;
    if (coord[0] == 'G')
        return 6;
    if (coord[0] == 'H')
        return 7;
}

void place_ship(int size, char *start, char *end)
{
    int x1, x2, y1, y2;

    x1 = get_x(start);
    x2 = get_x(end);
    y1 = (start[1] - 48) - 1;
    y2 = (end[1] - 48) - 1;
    while (x1 < x2 || y1 < y2) {
        nav->map_p1[x1][y1] = size + 48;
        if (x1 <= x2 && y1 == y2)
            x1 += 1;
        if (y1 < y2 && x1 == x2)
            y1 += 1;
        if (x1 == x2 && y1 == y2)
            nav->map_p1[x1][y1] = size + 48;
    }
}

void place_my_ships(char *buffer)
{
    int size = 0;
    char *start = malloc(sizeof(char) * 2);
    char *end = malloc(sizeof(char) * 2);

    for (int i = 0;; i += 8) {
        size = buffer[i] - 48;
        start[0] = buffer[i + 2];
        start[1] = buffer[i + 3];
        end[0] = buffer[i + 5];
        end[1] = buffer[i + 6];
        place_ship(size, start, end);
        if (buffer[i + 7] == '\0')
            break;
    }
}

char *get_coordinates(int fd, char *filepath)
{
    struct stat statbuf;
    char *buffer = NULL;
    int size = 0;

    stat(filepath, &statbuf);
    buffer = malloc(statbuf.st_size + 1);
    buffer[statbuf.st_size + 1] = '\0';
    size = read(fd, buffer, statbuf.st_size);
    close(fd);
    return buffer;

}

void fill_map(int ac, char **av)
{
    int fd;
    char *buffer;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        buffer = get_coordinates(fd, av[1]);
    } else {
        fd = open(av[2], O_RDONLY);
        buffer = get_coordinates(fd, av[2]);
    }
    place_my_ships(buffer);
}