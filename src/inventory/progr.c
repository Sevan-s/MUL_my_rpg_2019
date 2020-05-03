/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** progr.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void ini_progr(inventory_t *inventory, sfVector2f character)
{
    inventory->progress = 0;
    inventory->progr->texture = sfTexture_createFromFile(\
    "asset/texture/status.png", NULL);
    inventory->progr->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->progr->sprite, \
    inventory->progr->texture, sfTrue);
    inventory->box_progr.height = 20;
    inventory->box_progr.left = 0;
    inventory->box_progr.top = 60;
    inventory->box_progr.width = (450 * inventory->progress) / 100;
    inventory->progr->pos.x = 155 + character.x - 470;
    inventory->progr->pos.y = 30 + character.y - 450;
    inventory->progr->size.x = 0.35;
    inventory->progr->size.y = 0.35;
    sfSprite_setPosition(inventory->progr->sprite, inventory->progr->pos);
    sfSprite_setScale(inventory->progr->sprite, inventory->progr->size);
    sfSprite_setTextureRect(inventory->progr->sprite, inventory->box_progr);
    ini_progr_score(inventory, character);
}

void ini_progr_score(inventory_t *inventory, sfVector2f character)
{
    inventory->progr_text = sfText_create();
    inventory->progr_str = sfText_create();
    sfVector2f pos;
    pos.x = 250 + character.x - 480;
    pos.y = 0 + character.y - 450;

    sfText_setPosition(inventory->progr_str, pos);
    pos.x = 220 + character.x - 480;
    pos.y = 0 + character.y - 450;
    sfText_setPosition(inventory->progr_text, pos);
    sfText_setFont(inventory->progr_text, inventory->font);
    sfText_setFont(inventory->progr_str, inventory->font);
    sfText_setCharacterSize(inventory->progr_text, 20);
    sfText_setCharacterSize(inventory->progr_str, 20);
    sfText_setString(inventory->progr_str, "%");
    sfText_setString(inventory->progr_text, "0");
}

void display_progr(window_t *window_s, inventory_t *inventory, \
sfVector2f character)
{
    if (window_s->scene != 3) {
        resize_progr(inventory, character);
        if (inventory->progress > 0)
            sfText_setString(inventory->progr_text, \
            nbr_in_str(inventory->progress));
        inventory->box_progr.width = (450 * inventory->progress) / 100;
        sfSprite_setTextureRect(inventory->progr->sprite, inventory->box_progr);
        sfRenderWindow_drawSprite(window_s->window, \
        inventory->progr->sprite, NULL);
        sfRenderWindow_drawText(window_s->window, inventory->progr_str, NULL);
        sfRenderWindow_drawText(window_s->window, inventory->progr_text, NULL);
    }
}

void resize_progr(inventory_t *inventory, sfVector2f character)
{
    sfVector2f pos;
    pos.x = 250 + character.x - 480;
    pos.y = 0 + character.y - 450;
    sfText_setPosition(inventory->progr_str, pos);
    pos.x = 220 + character.x - 480;
    pos.y = 0 + character.y - 450;
    sfText_setPosition(inventory->progr_text, pos);
    inventory->progr->pos.x = 155 + character.x - 470;
    inventory->progr->pos.y = 30 + character.y - 450;
    sfSprite_setPosition(inventory->progr->sprite, inventory->progr->pos);
}

void destroy_progr(inventory_t *inventory)
{
    sfText_destroy(inventory->progr_str);
    sfText_destroy(inventory->progr_text);
    sfSprite_destroy(inventory->progr->sprite);
    sfTexture_destroy(inventory->progr->texture);
    sfFont_destroy(inventory->font);
}