/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** libmy
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include "struct.h"
#include "csfml.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
int my_getnbr(char const *str);
char *nbr_in_str(int nbr);

void game_loop(void);

void initialization(window_t *manag_window, start_t *start,\
background_t *background, list_t *my_list);
void display_parameter(window_t *manag_window);
void start_sprite(start_t *start);
void start_position(start_t *start);
void pause_sprite(start_t *start);
void pause_position(start_t *start);
void background_game_def(background_t *background);

list_t *enemy_ini(window_t *manag_window);
void enemy_insertion(list_t *liste, window_t *manag_window, int nb);
void enemy_sprite(enemy_t *enemy, window_t *manag_window, int nb);

int analyse_events(sfEvent event, window_t *manag_window, start_t *start);
int button_click_detection(window_t *manag_window, start_t *start,\
sfEvent event);
int manage_mouse_click(sfMouseButtonEvent event, window_t *manag_window,\
start_t *start);
int manage_pause_menu_click(sfMouseButtonEvent event,\
window_t *manag_window, start_t *start);
void manage_pause_Escape(window_t *manag_window, start_t *start);
void manage_pause_click(sfMouseButtonEvent event, window_t *manag_window,\
start_t *start);

void menu(window_t *manag_window, start_t *start);
void menu_start(start_t *start, window_t *manag_window);
void menu_pause(start_t *start, window_t *manag_window);

void game(window_t *manag_window, background_t *background,\
list_t *list);

void move_enemy(enemy_t *enemy);
void move_sprite_ennemy_next(enemy_t *enemy);
void move_sprite_ennemy_(enemy_t *enemy);
void move_rectangle(sfIntRect *rect);


void destroy_all(window_t *manag_window, list_t *list,\
background_t *background, start_t *start);
void destroy_start(start_t *start);
void destroy_background(background_t *background);
void destroy_window(window_t *manag_window);
void destroy_enemy(list_t *list);

#endif /* !LIBMY_H_ */