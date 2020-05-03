/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** zombie_attack.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void zombie_attack(window_t *window_s, combat_t *combat)
{
    if (combat->z_stunned == 0) {
        sfSound_play(combat->attack);
        combat->box_player_pv.width -= 83;
        combat->pv -= 10;
        sfSprite_setTextureRect(combat->player_pv->sprite, \
        combat->box_player_pv);
        sfRenderWindow_drawSprite(window_s->window, combat->player_pv->sprite, \
        NULL);
    }
    else if (combat->z_stunned == 2)
        combat->z_stunned = 1;
    else
        combat->z_stunned = 0;
    combat->turn = 1;
}