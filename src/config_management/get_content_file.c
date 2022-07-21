/*
** EPITECH PROJECT, 2022
** get_content_file
** File description:
** Source code to get content of a file
*/
#include "get_content_file.h"

char **get_content_file(char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    char *buff;
    char **content;

    if (fd == -1) {
        write_error("Error: Cannot find:");
        write_error(pathname);
        write_error("\n");
        return (NULL);
    }
    buff = get_content(fd);
    if (count_char(buff, '\n') < 1) {
        free(buff);
        return (NULL);
    }
    content = my_split(buff, '\n');
    free(buff);
    return (content);
}
