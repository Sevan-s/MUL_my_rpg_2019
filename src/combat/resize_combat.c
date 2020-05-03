/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** resize_combat.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void resize_combat(inventory_t *inventory)
{
    inventory->pistol->size.x = 0.22;
    inventory->pistol->size.y = 0.22;
    sfSprite_setScale(inventory->pistol->sprite, inventory->pistol->size);
    inventory->grenade->size.x = 0.6;
    inventory->grenade->size.y = 0.6;
    sfSprite_setScale(inventory->grenade->sprite, inventory->grenade->size);
    inventory->medic->size.x = 0.08;
    inventory->medic->size.y = 0.08;
    sfSprite_setScale(inventory->medic->sprite, inventory->medic->size);
    inventory->throw_knife->size.x = 0.2;
    inventory->throw_knife->size.y = 0.2;
    sfSprite_setScale(inventory->throw_knife->sprite, \
    inventory->throw_knife->size);
    replace_combat(inventory);
}

void replace_combat(inventory_t *inventory)
{
    inventory->pistol->pos.x = 15;
    inventory->pistol->pos.y = 60;
    sfSprite_setPosition(inventory->pistol->sprite, inventory->pistol->pos);
    inventory->grenade->pos.x = 20;
    inventory->grenade->pos.y = 130;
    sfSprite_setPosition(inventory->grenade->sprite, inventory->grenade->pos);
    inventory->medic->pos.x = 260;
    inventory->medic->pos.y = 55;
    sfSprite_setPosition(inventory->medic->sprite, inventory->medic->pos);
    inventory->throw_knife->pos.x = 200;
    inventory->throw_knife->pos.y = 170;
    sfSprite_setPosition(inventory->throw_knife->sprite, \
    inventory->throw_knife->pos);
}