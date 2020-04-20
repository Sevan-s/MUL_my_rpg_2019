/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void display_parameter(window_t *manage_window)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    manage_window->window = sfRenderWindow_create(video_mode,
    "My_Defender", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(manage_window->window, 60);
}

void initialization(hub_t *hub)
{
    hub->manage_window->scene = 0;
    display_parameter(hub->manage_window);
    start_sprite(hub->start);
    start_position(hub->start);
    pause_sprite(hub->start);
    pause_position(hub->start);
    hub->manage_window->game = sfMusic_createFromFile\
    ("asset/music/game_music.ogg");
    background_game_ini(hub->background);
}

void menu(hub_t *hub)
{
    if (hub->manage_window->scene == 0)
        menu_start(hub->start, hub->manage_window);
    if (hub->manage_window->scene == 2)
        menu_pause(hub->start, hub->manage_window);
}

void structuring_malloc(hub_t *hub)
{
    hub->manage_window = malloc(sizeof(window_t));
    hub->background = malloc(sizeof(background_t));
    hub->start = malloc(sizeof(start_t));
}

void game_loop(void)
{
    hub_t *hub = malloc(sizeof(hub_t));
    int result = 0;

    structuring_malloc(hub);
    initialization(hub);
    while (sfRenderWindow_isOpen(hub->manage_window->window) && result == 0) {
        result = analyse_events(hub);
        sfRenderWindow_clear(hub->manage_window->window, sfBlack);
        menu(hub);
        if (hub->manage_window->scene == 1)
            game_display(hub);
        sfRenderWindow_display(hub->manage_window->window);
    }
    destroy_all(hub);
}
