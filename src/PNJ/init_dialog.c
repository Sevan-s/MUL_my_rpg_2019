/*
** EPITECH PROJECT, 2020
** init_dialog
** File description:
** init_dialog
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void position_sprite_dialog(hub_t *hub)
{
    hub->dialog->position_pnj_dialog.x = (\
    hub->pnj->position_actual_character.x - 280);
    hub->dialog->position_pnj_dialog.y = (\
    hub->pnj->position_actual_character.y + 280);
    sfSprite_setPosition(hub->dialog->sprite_pnj1_dialog1, \
    hub->dialog->position_pnj_dialog);
    sfSprite_setPosition(hub->dialog->sprite_pnj1_dialog2, \
    hub->dialog->position_pnj_dialog);
    sfSprite_setPosition(hub->dialog->sprite_pnj2_dialog1, \
    hub->dialog->position_pnj_dialog);
}

void sprite_with_texture(hub_t *hub)
{
    sfSprite_setTexture(hub->dialog->sprite_pnj1_dialog1, \
    hub->dialog->texture_pnj1_dialog1, sfTrue);
    sfSprite_setTexture(hub->dialog->sprite_pnj1_dialog2, \
    hub->dialog->texture_pnj1_dialog2, sfTrue);
    sfSprite_setTexture(hub->dialog->sprite_pnj2_dialog1, \
    hub->dialog->texture_pnj2_dialog1, sfTrue);
}

void sprite_dialog(hub_t *hub)
{
    hub->dialog->sprite_pnj1_dialog1 = sfSprite_create();
    hub->dialog->sprite_pnj1_dialog2 = sfSprite_create();
    hub->dialog->sprite_pnj2_dialog1 = sfSprite_create();
    sprite_with_texture(hub);
}

void texture_dialog(hub_t *hub)
{
    hub->dialog->texture_pnj1_dialog1 = sfTexture_createFromFile(\
    "asset/dialog/PNJ1_dialog1.png", NULL);
    hub->dialog->texture_pnj1_dialog2 = sfTexture_createFromFile(\
    "asset/dialog/PNJ1_dialog2.png", NULL);
    hub->dialog->texture_pnj2_dialog1 = sfTexture_createFromFile(\
    "asset/dialog/PNJ2_dialog1.png", NULL);
    sprite_dialog(hub);
}