/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void game_display(hub_t *hub)
{
    sfRenderWindow_drawSprite(hub->manage_window->window,\
    hub->background->sprite_background_game, NULL);
    sfRenderWindow_drawSprite(hub->manage_window->window,\
    hub->background->sprite_pause_game, NULL);
}