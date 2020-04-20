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

//game_loop
void game_loop(void);

//initialization_function
void structuring_malloc(hub_t *hub);
void initialization(hub_t *hub);
void display_parameter(window_t *manage_window);
void start_sprite(start_t *start);
void start_position(start_t *start);
void pause_sprite(start_t *start);
void pause_position(start_t *start);
void background_game_ini(background_t *background);

//analyse_events_function
int analyse_events(hub_t *hub);
int button_click_detection(hub_t *hub);
int manage_mouse_click(sfMouseButtonEvent event, window_t *manage_window,\
start_t *start);
int manage_pause_menu_click(sfMouseButtonEvent event,\
window_t *manage_window, start_t *start);
void manage_pause_Escape(window_t *manage_window, start_t *start);
void manage_pause_click(sfMouseButtonEvent event, window_t *manage_window,\
start_t *start);

//menu_function
void menu(hub_t *hub);
void menu_start(start_t *start, window_t *manage_window);
void menu_pause(start_t *start, window_t *manage_window);

//display_function
void game_display(hub_t *hub);

//destroy_function
void destroy_all(hub_t *hub);
void destroy_start(start_t *start);
void destroy_background(background_t *background);
void destroy_window(window_t *manage_window);

#endif /* !LIBMY_H_ */