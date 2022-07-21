##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile to compile the lib
##

SRC =	fonctions/count_char.c		\
		fonctions/get_content.c 	\
		fonctions/my_split.c	 	\
		fonctions/my_strlen.c 	 	\
		fonctions/my_strncpy.c	 	\
		fonctions/next_char.c		\
		fonctions/my_strconc.c		\
		fonctions/write_error.c		\
		fonctions/add_char.c		\
		fonctions/my_realloc.c		\
		fonctions/my_strcmp.c		\
		fonctions/my_getnbr.c		\
		fonctions/my_putstr.c		\
		fonctions/my_putchar.c		\
		fonctions/my_strcpy.c		\
		fonctions/my_atof.c			\
		fonctions/free_tab.c 		\
		fonctions/count_line.c		\
		fonctions/my_printf.c 		\
		fonctions/my_putnbr.c		\
		fonctions/my_strdup.c		\
		fonctions/get_nb_row_tab.c	\
		fonctions/my_getstr.c


NAME =	libmy.a

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
