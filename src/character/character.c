/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void initialization_character(character_t *character)
{
    character->clock = sfClock_create();
    character->move_clock = sfClock_create();
    character->texture_character = sfTexture_createFromFile(\
    "asset/texture/player_opt.png", NULL);
    character->sprite_character = sfSprite_create();
    sfSprite_setTexture(character->sprite_character, \
    character->texture_character, sfTrue);
    character->position_character = (sfVector2f){500, 500};
    sfSprite_setPosition(character->sprite_character, \
    character->position_character);
    character->rect_character = (sfIntRect){0, 0, 50, 55};
    sfSprite_setTextureRect(character->sprite_character, \
    character->rect_character);
}

void set_pnj_clock(character_t *character)
{
    float seconds;

    character->move_time = \
    sfClock_getElapsedTime(character->move_clock).microseconds;
    seconds = character->move_time / 100000;
    if (seconds > 1) {
        character->rect_character.left += 50;
        sfSprite_setTextureRect(character->sprite_character,
        character->rect_character);
        sfClock_restart(character->move_clock);
    }
    if (character->rect_character.left >= 150) {
        character->rect_character.left = 0;
        sfSprite_setTextureRect(character->sprite_character, \
        character->rect_character);
    }
}
