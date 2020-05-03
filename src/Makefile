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
		  ./struct_alloc.c \
		  ./menu/menu_start.c \
		  ./menu/menu_pause.c \
		  ./menu/menu_htp.c \
		  ./display.c \
		  ./initialization.c \
		  ./event_analysis.c \
		  ./switch_event.c \
		  ./manage_escape.c \
		  ./inventory/ini_items.c \
		  ./inventory/inventory_event.c \
		  ./inventory/inventory.c \
		  ./inventory/resize_inventory.c \
		  ./inventory/progr.c \
		  ./combat/combat_ini.c \
		  ./combat/combat_ini_sec.c \
		  ./combat/combat_scene.c \
		  ./combat/resize_combat.c \
		  ./combat/combat_core.c \
		  ./combat/zombie_attack.c \
		  ./combat/combat_evnt_anlys.c \
		  ./combat/cut.c \
		  ./combat/result.c \
		  ./character/character.c \
		  ./character/move_character.c \
		  ./destroy/destroy_all.c \
		  ./destroy/destroy_combat.c\
		  ./destroy/destroy_inventory.c\
		  ./display_rain.c \
		  ./collision_detection/read_map_collision.c \
		  ./PNJ/pnj_detect.c \
		  ./PNJ/pnj_dialog.c \
		  ./PNJ/init_dialog.c \
		  ./quests/init_quests.c \
		  ./quests/display_quest.c \

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
