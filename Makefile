
NAME = JeuDeLaVie

CC = gcc

INC = -I./inc/

SRC = ./src/*.c

OPT = -lSDL2-2.0

all: $(NAME)

$(NAME):
	$(CC) $(INC) $(SRC) -o $(NAME) $(OPT)

clean:
	/bin/rm -f $(NAME)

re: clean all

.PHONY: all clean re
