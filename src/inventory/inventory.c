/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void inventory_ini(inventory_t *inventory, character_t *character)
{
    inventory->state = 0;
    init_grenade(inventory, character->position_character);
    init_medic(inventory, character->position_character);
    init_pistol(inventory, character->position_character);
    init_throw(inventory, character->position_character);
    back_ini(inventory, character->position_character);
    ini_pv(inventory, character->position_character);
    ini_progr(inventory, character->position_character);
}

void ini_pv(inventory_t *inventory, sfVector2f character)
{
    inventory->pv_text = sfText_create();
    inventory->pv_str = sfText_create();
    sfVector2f text;
    inventory->font = sfFont_createFromFile("asset/police/arial.ttf");
    text.x = 0 + character.x - 450;
    text.y = 0 + character.y - 450;

    sfText_setPosition(inventory->pv_str, text);
    text.x = 70 + character.x - 450;
    text.y = 0 + character.y - 450;
    sfText_setPosition(inventory->pv_text, text);
    sfText_setFont(inventory->pv_text, inventory->font);
    sfText_setFont(inventory->pv_str, inventory->font);
    sfText_setCharacterSize(inventory->pv_text, 40);
    sfText_setCharacterSize(inventory->pv_str, 40);
    sfText_setString(inventory->pv_str, "PV: ");
}

void inventory_display(window_t *window_s, inventory_t *inventory, hub_t *hub)
{
    resize_inventory(inventory, hub->character->position_character, window_s);
    if (window_s->scene == 3)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->back->sprite, NULL);
    if (inventory->grenade_nb > 0)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->grenade->sprite, NULL);
    if (inventory->pistol_nb > 0)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->pistol->sprite, NULL);
    if (inventory->throw_knife_nb > 0)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->throw_knife->sprite, NULL);
    if (inventory->medic_nb > 0)
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->medic->sprite, NULL);
    display_pv(window_s, inventory, hub);
    display_progr(window_s, inventory, hub->character->position_character);
}

void display_pv(window_t *window_s, inventory_t *inventory, hub_t *hub)
{
    sfVector2f text;
    if (window_s->scene == 1) {
        text.x = 0 + hub->character->position_character.x - 450;
        text.y = 0 + hub->character->position_character.y - 450;
        sfText_setPosition(inventory->pv_str, text);
        text.x = 70 + hub->character->position_character.x - 450;
        text.y = 0 + hub->character->position_character.y - 450;
        sfText_setPosition(inventory->pv_text, text);
        sfRenderWindow_drawText(window_s->window, \
        inventory->pv_text, NULL);
        sfRenderWindow_drawText(window_s->window, \
        inventory->pv_str, NULL);
    }
}

void reward(inventory_t *inventory)
{
    int reward = rand() / 100000000;

    if (reward <= 8)
        inventory->pistol_nb += 1;
    if (reward > 8 && reward <= 14)
        inventory->grenade_nb += 1;
    if (reward > 14 && reward <= 18)
        inventory->medic_nb += 1;
    if (reward > 18)
        inventory->throw_knife_nb += 1;
}