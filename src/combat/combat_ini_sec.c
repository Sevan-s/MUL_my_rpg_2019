/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** combat_ini_sec.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void combat_ini_scene(combat_t *combat)
{
    combat->text_background = sfTexture_createFromFile( \
    "asset/texture/combat/back.png", NULL);
    combat->background = sfSprite_create();
    sfSprite_setTexture(combat->background, \
    combat->text_background, sfTrue);
    combat->player_pv->texture = sfTexture_createFromFile(\
    "asset/texture/combat/pv.png", NULL);
    combat->enemy_pv->texture = sfTexture_createFromFile(\
    "asset/texture/combat/pv.png", NULL);
    combat->music = sfMusic_createFromFile("asset/music/combat.ogg");
}

void combat_ini_cut(combat_t *combat)
{
    combat->cut->texture = sfTexture_createFromFile(\
    "asset/texture/combat/cut.png", NULL);
    combat->cut->sprite = sfSprite_create();
    sfSprite_setTexture(combat->cut->sprite, \
    combat->cut->texture, sfTrue);
    combat->cut->pos.x = 20;
    combat->cut->pos.y = 30;
    combat->cut->size.x = 1;
    combat->cut->size.y = 1;
    sfSprite_setPosition(combat->cut->sprite, combat->cut->pos);
    sfSprite_setScale(combat->cut->sprite, combat->cut->size);
    combat->axe = sfSound_create();
    combat->axe_buff = sfSoundBuffer_createFromFile(\
    "asset/music/cut.ogg");
    sfSound_setBuffer(combat->axe, combat->axe_buff);
}

void combat_ini_bag(combat_t *combat)
{
    combat->bag->texture = sfTexture_createFromFile(\
    "asset/texture/combat/bag_p.png", NULL);
    combat->bag->sprite = sfSprite_create();
    sfSprite_setTexture(combat->bag->sprite, \
    combat->bag->texture, sfTrue);
    combat->bag->pos.x = 250;
    combat->bag->pos.y = 30;
    combat->bag->size.x = 1;
    combat->bag->size.y = 1;
    sfSprite_setPosition(combat->bag->sprite, combat->bag->pos);
    sfSprite_setScale(combat->bag->sprite, combat->bag->size);
    combat->search = sfSound_create();
    combat->search_buff = sfSoundBuffer_createFromFile(\
    "asset/music/searching.ogg");
    sfSound_setBuffer(combat->search, combat->search_buff);
}

void combat_ini_flee(combat_t *combat)
{
    combat->flee->texture = sfTexture_createFromFile(\
    "asset/texture/combat/flee.png", NULL);
    combat->flee->sprite = sfSprite_create();
    sfSprite_setTexture(combat->flee->sprite, \
    combat->flee->texture, sfTrue);
    combat->flee->pos.x = 20;
    combat->flee->pos.y = 150;
    combat->flee->size.x = 1;
    combat->flee->size.y = 1;
    sfSprite_setPosition(combat->flee->sprite, combat->flee->pos);
    sfSprite_setScale(combat->flee->sprite, combat->flee->size);
}

void combat_ini_pause(combat_t *combat)
{
    combat->pause->texture = sfTexture_createFromFile(\
    "asset/texture/combat/pause.png", NULL);
    combat->pause->sprite = sfSprite_create();
    sfSprite_setTexture(combat->pause->sprite, \
    combat->pause->texture, sfTrue);
    combat->pause->pos.x = 260;
    combat->pause->pos.y = 100;
    combat->pause->size.x = 0.13;
    combat->pause->size.y = 0.13;
    sfSprite_setPosition(combat->pause->sprite, combat->pause->pos);
    sfSprite_setScale(combat->pause->sprite, combat->pause->size);
}