/*
** EPITECH PROJECT, 2020
** inits_quests
** File description:
** inits_quests
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void position_sprites_quests(hub_t *hub)
{
    hub->quests->position_quests.x = (\
    hub->character->position_character.x - 125);
    hub->quests->position_quests.y = (\
    hub->character->position_character.y - 450);
    sfSprite_setPosition(hub->quests->sprite_quest1, \
    hub->quests->position_quests);
    sfSprite_setPosition(hub->quests->sprite_success, \
    hub->quests->position_quests);
}

void sprites_with_textures_quests(hub_t *hub)
{
    sfSprite_setTexture(hub->quests->sprite_quest1, \
    hub->quests->texture_quest1, sfTrue);
    sfSprite_setTexture(hub->quests->sprite_success, \
    hub->quests->texture_success, sfTrue);
}

void init_sprites_quests(hub_t *hub)
{
    hub->quests->sprite_quest1 = sfSprite_create();
    hub->quests->sprite_success = sfSprite_create();
    sprites_with_textures_quests(hub);
}

void init_quests(hub_t *hub)
{
    hub->quests->texture_quest1 = sfTexture_createFromFile(\
    "asset/quests/quest1.png", NULL);
    hub->quests->texture_success = sfTexture_createFromFile(\
    "asset/quests/success.png", NULL);
    init_sprites_quests(hub);
}