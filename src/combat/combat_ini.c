/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** combat_ini.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void combat_ini(combat_t *combat, window_t *window_s)
{
    combat->check = 1;
    window_s->scene_save = 3;
    if (combat->pv_e <= 0)
        combat->pv_e = 100;
    combat->inventory = 0;
    combat->turn = 1;
    combat_ini_scene(combat);
    combat_ini_cut(combat);
    combat_ini_bag(combat);
    combat_ini_flee(combat);
    combat_ini_pv_e(combat);
    combat_ini_pv_p(combat);
    combat_ini_enemy(combat);
    combat_ini_player(combat);
    combat_ini_pause(combat);
    combat->clock = sfClock_create();
    sfMusic_play(combat->music);
    sfMusic_setLoop(combat->music, sfTrue);
}

void combat_ini_pv_p(combat_t *combat)
{
    combat->player_pv->sprite = sfSprite_create();
    sfSprite_setTexture(combat->player_pv->sprite, \
    combat->player_pv->texture, sfTrue);
    combat->box_player_pv.height = 100;
    combat->box_player_pv.left = 0;
    combat->box_player_pv.top = 0;
    combat->box_player_pv.width = (830 * combat->pv) / 100;
    combat->player_pv->pos.x = 200;
    combat->player_pv->pos.y = 950;
    combat->player_pv->size.x = 0.5;
    combat->player_pv->size.y = 0.7;
    sfSprite_setTextureRect(combat->player_pv->sprite, combat->box_player_pv);
    sfSprite_setScale(combat->player_pv->sprite, combat->player_pv->size);
    sfSprite_setPosition(combat->player_pv->sprite, combat->player_pv->pos);
}

void combat_ini_pv_e(combat_t *combat)
{
    combat->enemy_pv->sprite = sfSprite_create();
    sfSprite_setTexture(combat->enemy_pv->sprite, \
    combat->enemy_pv->texture, sfTrue);
    combat->box_enemy_pv.height = 100;
    combat->box_enemy_pv.left = 0;
    combat->box_enemy_pv.top = 0;
    combat->box_enemy_pv.width = (830 * combat->pv_e) / 100;
    combat->enemy_pv->pos.x = 1300;
    combat->enemy_pv->pos.y = 950;
    combat->enemy_pv->size.x = 0.5;
    combat->enemy_pv->size.y = 0.7;
    sfSprite_setTextureRect(combat->enemy_pv->sprite, combat->box_enemy_pv);
    sfSprite_setScale(combat->enemy_pv->sprite, combat->enemy_pv->size);
    sfSprite_setPosition(combat->enemy_pv->sprite, combat->enemy_pv->pos);
}

void combat_ini_player(combat_t *combat)
{
    combat->player->texture = sfTexture_createFromFile(\
    "asset/texture/combat/player_combat.png", NULL);
    combat->player->sprite = sfSprite_create();
    sfSprite_setTexture(combat->player->sprite, \
    combat->player->texture, sfTrue);
    combat->box_player.height = 110;
    combat->box_player.left = 0;
    combat->box_player.top = 114;
    combat->box_player.width = 80;
    combat->player->pos.x = 300;
    combat->player->pos.y = 420;
    combat->player->size.x = 5;
    combat->player->size.y = 5;
    sfSprite_setTextureRect(combat->player->sprite, combat->box_player);
    sfSprite_setScale(combat->player->sprite, combat->player->size);
    sfSprite_setPosition(combat->player->sprite, combat->player->pos);
}

void combat_ini_enemy(combat_t *combat)
{
    combat->enemy->texture = sfTexture_createFromFile(\
    "asset/texture/combat/zombie_combat.png", NULL);
    combat->enemy->sprite = sfSprite_create();
    sfSprite_setTexture(combat->enemy->sprite, \
    combat->enemy->texture, sfTrue);
    combat->box_enemy.height = 100;
    combat->box_enemy.left = 0;
    combat->box_enemy.top = 0;
    combat->box_enemy.width = 100;
    combat->enemy->pos.x = 1200;
    combat->enemy->pos.y = 500;
    combat->enemy->size.x = 4.6;
    combat->enemy->size.y = 4.6;
    sfSprite_setTextureRect(combat->enemy->sprite, combat->box_enemy);
    sfSprite_setScale(combat->enemy->sprite, combat->enemy->size);
    sfSprite_setPosition(combat->enemy->sprite, combat->enemy->pos);
    combat->attack = sfSound_create();
    combat->attack_buff = sfSoundBuffer_createFromFile(\
    "asset/music/z_attack.ogg");
    sfSound_setBuffer(combat->attack, combat->attack_buff);
}