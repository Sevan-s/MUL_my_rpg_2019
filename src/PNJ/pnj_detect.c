/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** PNJ_detect.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void pnj_targeted(hub_t *hub)
{
    if (hub->dialog->dialog_statut == 1) {
        position_sprite_dialog(hub);
        if (hub->manage_window->event.key.code == sfKeyEnter)
            hub->dialog->dialog_actual++;
    }
}

void detect_pnj(hub_t *hub)
{
    if (hub->manage_window->event.key.code == sfKeyT) {
        hub->pnj->position_actual_character = sfSprite_getPosition(\
        hub->character->sprite_character);
        if (hub->pnj->position_actual_character.x > 540 && \
        hub->pnj->position_actual_character.x < 672) {
            if (hub->pnj->position_actual_character.y > 310 && \
            hub->pnj->position_actual_character.y < 505) {
                hub->pnj->pnj_actual = 1;
                hub->dialog->dialog_actual = 1;
                hub->dialog->dialog_statut = 1;
            }
        }
        detect_pnj_sec(hub);
    }
    pnj_targeted(hub);
}

void detect_pnj_sec(hub_t *hub)
{
    if (hub->pnj->position_actual_character.x > 1475 && \
        hub->pnj->position_actual_character.x < 1605) {
            if (hub->pnj->position_actual_character.y > 89 && \
            hub->pnj->position_actual_character.y < 275) {
                hub->pnj->pnj_actual = 2;
                hub->dialog->dialog_actual = 1;
                hub->dialog->dialog_statut = 1;
            }
    }
}

void position_PNJ(hub_t *hub)
{
    hub->pnj->position_pnj2.x = 1530;
    hub->pnj->position_pnj2.y = 170;
    sfSprite_setPosition(hub->pnj->sprite_pnj2, \
    hub->pnj->position_pnj2);
    hub->pnj->position_pnj.x = 600;
    hub->pnj->position_pnj.y = 400;
    sfSprite_setPosition(hub->pnj->sprite_pnj, \
    hub->pnj->position_pnj);
    hub->pnj->position_pnj3.x = 520;
    hub->pnj->position_pnj3.y = 150;
    sfSprite_setPosition(hub->pnj->sprite_pnj3, \
    hub->pnj->position_pnj3);
}

void init_PNJ(hub_t *hub)
{
    hub->pnj->texture_pnj = sfTexture_createFromFile(\
    "asset/texture/PNJ2.png", NULL);
    hub->pnj->sprite_pnj = sfSprite_create();
    sfSprite_setTexture(hub->pnj->sprite_pnj, hub->pnj->texture_pnj, sfTrue);
    hub->pnj->texture_pnj2 = sfTexture_createFromFile(\
    "asset/texture/zombie1.png", NULL);
    hub->pnj->sprite_pnj2 = sfSprite_create();
    sfSprite_setTexture(hub->pnj->sprite_pnj2, hub->pnj->texture_pnj2, sfTrue);
    hub->pnj->texture_pnj3 = sfTexture_createFromFile(\
    "asset/texture/zombie2.png", NULL);
    hub->pnj->sprite_pnj3 = sfSprite_create();
    sfSprite_setTexture(hub->pnj->sprite_pnj3, hub->pnj->texture_pnj3, sfTrue);
    position_PNJ(hub);
}