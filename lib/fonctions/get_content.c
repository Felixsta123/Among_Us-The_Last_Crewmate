/*
** EPITECH PROJECT, 2022
** get_content
** File description:
** Source code to get everything in a file into a str
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

char *add_char(char *str, char c);

char *get_content(int fd)
{
    char *str = malloc(1);
    char *readed = malloc(2);

    str[0] = '\0';
    if (fd == -1) {
        return (NULL);
    }
    while (read(fd, readed, 1) != 0) {
        str = add_char(str, readed[0]);
    }
    str = add_char(str, '\0');
    free(readed);
    return (str);
}
