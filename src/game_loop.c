/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void display_parameter(window_t *manag_window)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    manag_window->window = sfRenderWindow_create(video_mode,
    "My_Defender", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(manag_window->window, 60);
}

void initialization(window_t *manag_window, start_t *start,\
background_t *background, list_t *my_list)
{
    display_parameter(manag_window);
    start_sprite(start);
    start_position(start);
    pause_sprite(start);
    pause_position(start);
    manag_window->game = sfMusic_createFromFile("asset/game_music.ogg");
    background_game_def(background);
    for (int nb = 5; nb <= 1000; nb += 20)
        enemy_insertion(my_list, manag_window, nb);
}

void menu(window_t *manag_window, start_t *start)
{
    if (manag_window->scene == 0)
        menu_start(start, manag_window);
    if (manag_window->scene == 2)
        menu_pause(start, manag_window);
}

void game_loop(void)
{
    window_t manag_window;
    start_t start;
    background_t background;
    sfEvent event;
    list_t *my_list = enemy_ini(&manag_window);
    manag_window.scene = 0;
    int result = 0;

    initialization(&manag_window, &start, &background, my_list);
    while (sfRenderWindow_isOpen(manag_window.window) && result == 0) {
        result = analyse_events(event, &manag_window, &start);
        sfRenderWindow_clear(manag_window.window, sfBlack);
        menu(&manag_window, &start);
        if (manag_window.scene == 1)
            game(&manag_window, &background, my_list);
        sfRenderWindow_display(manag_window.window);
    }
    destroy_all(&manag_window, my_list, &background, &start);
}