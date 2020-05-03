/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** cut.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void cut(hub_t *hub, window_t *window_s, combat_t *combat)
{
    float sec = 0;
    sfClock *move = sfClock_create();

    init_cut(combat);
    combat->time = sfClock_getElapsedTime(move);
    sec = combat->time.microseconds / 1000000.0;
    while (sec < 0.80) {
        check_first(hub, sec, window_s, combat);
        check_sec(hub, sec, window_s, combat);
        combat->time = sfClock_getElapsedTime(move);
        sec = combat->time.microseconds / 1000000.0;
    }
    combat->box_player.top = 114;
    sfClock_restart(combat->clock);
}

void init_cut(combat_t *combat)
{
    combat->box_player.top = 0;
    combat->box_player.left = 0;
    sfSound_play(combat->axe);
}

void sliced(window_t *window_s, combat_t *combat)
{
    combat->box_enemy_pv.width -= 166;
    combat->pv_e -= 20;
    sfSprite_setTextureRect(combat->enemy_pv->sprite, combat->box_enemy_pv);
    sfRenderWindow_drawSprite(window_s->window, combat->enemy_pv->sprite, NULL);
}

void check_first(hub_t *hub, float sec, window_t *window_s, combat_t *combat)
{
    if (sec == 0.25) {
        combat->box_player.left += 80;
        sfSprite_setTextureRect(combat->player->sprite, combat->box_player);
        sfRenderWindow_drawSprite(window_s->window, \
        combat->player->sprite, NULL);
        sfRenderWindow_display(window_s->window);
        display_combat(hub, combat, window_s);
    }
}

void check_sec(hub_t *hub, float sec, window_t *window_s, combat_t *combat)
{
    if (sec == 0.50) {
        sfRenderWindow_clear(window_s->window, sfBlack);
        combat->box_player.left += 80;
        sfSprite_setTextureRect(combat->player->sprite, combat->box_player);
        sfRenderWindow_drawSprite(window_s->window, \
        combat->player->sprite, NULL);
        sliced(window_s, combat);
        display_combat(hub, combat, window_s);
    }
}