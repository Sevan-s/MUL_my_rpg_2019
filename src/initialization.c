/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void background_game_ini(background_t *background)
{
    background->texture_background_game = sfTexture_createFromFile(\
    "asset/texture/background.png", NULL);
    background->sprite_background_game = sfSprite_create();
    sfSprite_setTexture(background->sprite_background_game,\
    background->texture_background_game, sfTrue);
    background->texture_pause_game = sfTexture_createFromFile(\
    "asset/texture/button/pause_game.png", NULL);
    background->sprite_pause_game = sfSprite_create();
    sfSprite_setTexture(background->sprite_pause_game,\
    background->texture_pause_game, sfTrue);
}