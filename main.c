/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-3-navy-gilbert.badiabo
** File description:
** main.c
*/

#include "include/navy.h"

navy_t *nav;

int check_file_content(char *buffer)
{
    for (int i = 0;; i += 8) {
        if (buffer[i] < '1' || buffer[i] > '8')
            return 84;
        if (buffer[i + 1] != ':')
            return 84;
        if (buffer[i + 2] < 'A' || buffer[i + 2] > 'H' &&
        buffer[i + 5] < 'A' || buffer[i + 5] > 'H')
            return 84;
        if (buffer[i + 3] < '1' || buffer[i + 3] > '8' &&
        buffer[i + 6] < '1' || buffer[i + 6] > '8')
            return 84;
        if (buffer[i + 4] != ':')
            return 84;
        if (buffer[i + 7] != '\n' && buffer[i + 7] != '\0')
            return 84;
        if (buffer[i + 7] == '\n' || buffer[i + 7] == '\0')
            break;
    }
    return 1;
}

int check_read_file(int fd, int ac, char *filepath)
{
    struct stat statbuf;
    char *buffer = NULL;
    int size = 0;

    stat(filepath, &statbuf);
    buffer = malloc(statbuf.st_size + 1);
    buffer[statbuf.st_size + 1] = '\0';
    size = read(fd, buffer, statbuf.st_size);
    if (size == -1)
        return 84;
    if (check_file_content(buffer) == 84)
        return 84;
    close(fd);
    return 1;
}

int check_file(int ac, char **av)
{
    int fd = 0;

    if (ac == 2) {
        if (open(av[1], O_RDONLY) == -1)
            return 84;
        if (check_read_file(open(av[1], O_RDONLY), ac, av[1]) == 84)
            return 84;
    }
    if (ac == 3) {
        if (open(av[2], O_RDONLY) == -1)
            return 84;
        if (check_read_file(open(av[2], O_RDONLY), ac, av[2]) == 84)
            return 84;
    }
}

int check_arg(int ac, char **av)
{
    int check = 0;

    if (ac < 2 || ac > 3)
        return 84;
    if (check_file(ac, av) == 84)
        return 84;
    if (ac == 3 && my_str_isnum(av[1]) == 0 || ac == 3 && my_getnbr(av[1]) <= 0)
        return 84;
}

int main(int ac, char *av[])
{
    struct sigaction p1;
    struct sigaction p2;
    int res = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        readme();
        return 0;
    }
    if (check_arg(ac, av) == 84)
        return 84;
    init_sigaction(p1, p2);
    init_global();
    init_map(ac, av);
    if (ac == 2)
        res = player_one(ac, av, p1);
    if (ac == 3)
        res = player_two(ac, av, p2);
    end_message(res);
    free_struct();
    return 0;
}
