/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** resize_inventory.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void resize_inventory(inventory_t *inventory, sfVector2f character, \
window_t *window_s)
{
    if (window_s->scene == 3)
        resize_combat(inventory);
    else {
        resize_inv_map(inventory);
        replace_inv_map(inventory, window_s, character);
    }
}

void resize_inv_map(inventory_t *inventory)
{
    inventory->grenade->size.x = 0.4;
    inventory->grenade->size.y = 0.4;
    sfSprite_setScale(inventory->grenade->sprite, inventory->grenade->size);
    inventory->pistol->size.x = 0.15;
    inventory->pistol->size.y = 0.15;
    sfSprite_setScale(inventory->pistol->sprite, inventory->pistol->size);
    inventory->medic->size.x = 0.05;
    inventory->medic->size.y = 0.05;
    sfSprite_setScale(inventory->medic->sprite, inventory->medic->size);
    inventory->throw_knife->size.x = 0.12;
    inventory->throw_knife->size.y = 0.12;
    sfSprite_setScale(inventory->throw_knife->sprite, \
    inventory->throw_knife->size);
}

void replace_inv_map(inventory_t *inventory, window_t *window_s, \
sfVector2f character)
{
    inventory->pos_menu.x = -200 + character.x - 550;
    inventory->pos_menu.y = -50 + character.y - 470;
    sfSprite_setPosition(inventory->menu, inventory->pos_menu);
    inventory->throw_knife->pos.x = 200 + character.x - 480;
    inventory->throw_knife->pos.y = 170 + character.y - 450;
    sfSprite_setPosition(inventory->throw_knife->sprite, \
    inventory->throw_knife->pos);
    inventory->medic->pos.x = 250 + character.x - 500;
    inventory->medic->pos.y = 60 + character.y - 450;
    sfSprite_setPosition(inventory->medic->sprite, inventory->medic->pos);
    inventory->pistol->pos.x = 20 + character.x - 450;
    inventory->pistol->pos.y = 70 + character.y - 450;
    sfSprite_setPosition(inventory->pistol->sprite, inventory->pistol->pos);
    inventory->grenade->pos.x = 20 + character.x - 450;
    inventory->grenade->pos.y = 130 + character.y - 450;
    sfSprite_setPosition(inventory->grenade->sprite, \
    inventory->grenade->pos);
    if (window_s->scene != 3)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->menu, NULL);
}

void detect_medic(inventory_t *inventory, hub_t *hub, \
sfMouseButtonEvent event)
{
    if (event.x >= -80 + hub->character->position_character.x && \
        event.x <= 70 + hub->character->position_character.x) {
        if (event.y >= -420 + hub->character->position_character.y && \
        event.y <= -370 + hub->character->position_character.y && \
        inventory->medic_nb > 0 && hub->manage_window->scene != 3)
            medic(inventory, hub);
    }
    else if (event.x >= 260 && event.x <= 370 && \
    hub->manage_window->scene == 3) {
        if (event.y >= 55 && event.y <= 150)
            medic(inventory, hub);
    }
}