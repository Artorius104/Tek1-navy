##
## EPITECH PROJECT, 2020
## CPool_Day10_2020
## File description:
## Makefile
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c -I ../../include $(SRC)
	ar rc -o $(NAME) $(OBJ)
	cp libmy.a ../
	cp my.h ../../include

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
