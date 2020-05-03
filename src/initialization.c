/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void background_game_ini(hub_t *hub)
{
    hub->background->texture_background_game = sfTexture_createFromFile(\
    "asset/texture/map.png", NULL);
    hub->background->sprite_background_game = sfSprite_create();
    sfSprite_setTexture(hub->background->sprite_background_game, \
    hub->background->texture_background_game, sfTrue);
    hub->background->texture_pause_game = sfTexture_createFromFile(\
    "asset/texture/button/pause_game.png", NULL);
    hub->background->sprite_pause_game = sfSprite_create();
    sfSprite_setTexture(hub->background->sprite_pause_game, \
    hub->background->texture_pause_game, sfTrue);
    hub->background->position_pause = (sfVector2f){1813, 0};
    sfSprite_setPosition(hub->background->sprite_pause_game, \
    hub->background->position_pause);
}

void effects_game_ini(effects_t *effects)
{
    effects->texture_fire = sfTexture_createFromFile(\
    "asset/texture/fire.png", NULL);
    effects->sprite_fire = sfSprite_create();
    sfSprite_setTexture(effects->sprite_fire, \
    effects->texture_fire, sfTrue);
    effects->rect_fire = (sfIntRect){0, 0, 64, 128};
    sfSprite_setTextureRect(effects->sprite_fire, \
    effects->rect_fire);
    effects->position_fire = (sfVector2f){500, 500};
    sfSprite_setPosition(effects->sprite_fire, \
    effects->position_fire);
}

void display_fight_view(hub_t *hub)
{
    sfFloatRect rect_fight_view = {0, 0, 1920, 1080};
    hub->background->fight_view = sfView_createFromRect(rect_fight_view);
    sfRenderWindow_setView(hub->manage_window->window, \
    hub->background->fight_view);
}