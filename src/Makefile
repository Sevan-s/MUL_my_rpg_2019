##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## makefile
##

NAME	= ../my_rpg      \

CC	= gcc

RM	= rm -rf

SRCS	= ./main.c \
		  ./game_loop.c \
		  ./menu_start.c \
		  ./display.c \
		  ./menu_pause.c \
		  ./initialization.c \
		  ./event_analysis.c \
		  ./destroy_all.c \

OBJS	= $(SRCS:.c=.o)
CFLAGS += -W -Wall -Wextra -pedantic
LDFLAGS += -I./include -L../lib/my -lmy
DEBUGFLAGS = -g3
CSFMLGRAPHFLAGS = -l csfml-graphics
CSFMLSYSFLAGS = -l csfml-system
CSFMLAUDFLAGS = -l csfml-audio

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(CSFMLGRAPHFLAGS) $(CSFMLSYSFLAGS) $(CSFMLAUDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re