/*
** EPITECH PROJECT, 2022
** construct_background
** File description:
** Header
*/

#ifndef FILE_H_
    #define FILE_H_
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>

char *get_content(int fd);
char **my_split(char *str, char splitter);
int write_error(char const *str);
int count_char(char *str, char c);
#endif /*FILE_H_*/
