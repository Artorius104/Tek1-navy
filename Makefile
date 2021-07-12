##
## EPITECH PROJECT, 2020
## Navy
## File description:
## Makefile
##

SRC	=	main.c	\
		lib/src_navy/readme.c	\
		lib/src_navy/init.c	\
		lib/src_navy/free_all.c	\
		lib/src_navy/signals.c	\
		lib/src_navy/player_one.c	\
		lib/src_navy/player_two.c	\
		lib/src_navy/get_map.c	\
		lib/src_navy/display_map.c	\
		lib/src_navy/attack_event.c	\
		lib/src_navy/waiting_event.c	\
		lib/src_navy/check_win.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_str_isnum.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(NAME)

INCLUDE:	include

LIB:	./lib/my

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(SRC) -o $(NAME) -I ./$(INCLUDE) -L $(LIB) -g3 -lm
	rm *.o
	rm lib/src_navy/*.o
	rm lib/my/*.o

.PHONY: clean fclean re all

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all
