##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## makefile
##

NAME	= ../my_rpg      \

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
		  ./game_loop.c \
		  ./menu_start.c \
		  ./window.c \
		  ./menu_pause.c \
		  ./event_analysis.c \
		  ./destroy_all.c \
		  ./move_ennemy.c \

OBJS	= $(SRCS:.c=.o)
CFLAGS += -W -Wall -Wextra -pedantic -I./include -L../lib/my -lmy
GDBFLAGS = -g3
CSFMLGRAPHFLAGS = -l csfml-graphics
CSFMLSYSFLAGS = -l csfml-system
CSFMLAUDFLAGS = -l csfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(GDBFLAGS) $(CFLAGS) $(CSFMLGRAPHFLAGS) $(CSFMLSYSFLAGS) $(CSFMLAUDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re