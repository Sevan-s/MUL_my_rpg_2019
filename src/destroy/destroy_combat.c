/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_combat.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void destroy_combat(combat_t *combat)
{
    if (combat->check == 1) {
        sfMusic_destroy(combat->music);
        sfSprite_destroy(combat->background);
        sfSprite_destroy(combat->player_pv->sprite);
        sfSprite_destroy(combat->enemy_pv->sprite);
        sfSprite_destroy(combat->player->sprite);
        sfSprite_destroy(combat->enemy->sprite);
        sfSprite_destroy(combat->cut->sprite);
        sfSprite_destroy(combat->bag->sprite);
        sfSprite_destroy(combat->flee->sprite);
        sfTexture_destroy(combat->text_background);
        sfTexture_destroy(combat->player_pv->texture);
        sfTexture_destroy(combat->enemy_pv->texture);
        sfTexture_destroy(combat->player->texture);
        sfTexture_destroy(combat->enemy->texture);
        sfTexture_destroy(combat->cut->texture);
        sfTexture_destroy(combat->bag->texture);
        sfTexture_destroy(combat->flee->texture);
        destroy_combat_sec(combat);
    }
}

void destroy_combat_sec(combat_t *combat)
{
    sfTexture_destroy(combat->pause->texture);
    sfSprite_destroy(combat->pause->sprite);
    sfSound_destroy(combat->attack);
    sfSound_destroy(combat->axe);
    sfSound_destroy(combat->search);
    sfSoundBuffer_destroy(combat->attack_buff);
    sfSoundBuffer_destroy(combat->axe_buff);
    sfSoundBuffer_destroy(combat->search_buff);
}