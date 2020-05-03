/*
** EPITECH PROJECT, 2020
** display_quest
** File description:
** display_quest
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void display_quest(hub_t *hub)
{
    position_sprites_quests(hub);
    if (hub->quests->quest1 == 1) {
        sfRenderWindow_drawSprite(hub->manage_window->window, \
        hub->quests->sprite_quest1, NULL);
    }
    if (hub->quests->success == 1)
    {
        sfRenderWindow_drawSprite(hub->manage_window->window, \
        hub->quests->sprite_success, NULL);
    }
}