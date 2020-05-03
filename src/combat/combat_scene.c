/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** combat_window.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

int combat_scene(combat_t *combat, window_t *window_s, hub_t *hub)
{
    int outcome = 0;
    int result = 0;
    sfClock *z_move = sfClock_create();

    combat_ini(combat, window_s);
    hub->inventory->state = 0;
    combat->z_stunned = 0;
    while (sfRenderWindow_isOpen(window_s->window) && outcome == 0 && \
    result == 0 && window_s->scene == 3) {
        core(hub, &result, &outcome, z_move);
    }
    if (result_cmb(outcome, result, window_s, hub) == 1)
        return (1);
    return (0);
}

int check_life(combat_t *combat)
{
    if (combat->pv == 0)
        return (2);
    else if (combat->pv_e <= 0)
        return (1);
    return (0);
}

void animate(combat_t *combat, window_t *window_s)
{
    static float sec = 0;

    combat->time = sfClock_getElapsedTime(combat->clock);
    sec = combat->time.microseconds / 1000000.0;
    if (sec > 0.60) {
        idle(combat);
        sfSprite_setTextureRect(combat->player->sprite, combat->box_player);
        sfSprite_setTextureRect(combat->enemy->sprite, combat->box_enemy);
        combat->time = sfClock_restart(combat->clock);
    }
    sfRenderWindow_clear(window_s->window, sfBlack);
}

void idle(combat_t *combat)
{
    if (combat->box_player.left == 0)
        combat->box_player.left += 80;
    else
        combat->box_player.left = 0;
    if (combat->box_enemy.left == 0 && combat->box_enemy.top == 0)
        combat->box_enemy.left += 100;
    else if (combat->box_enemy.left == 100 && combat->box_enemy.top == 0) {
        combat->box_enemy.left = 0;
        combat->box_enemy.top += 100;
    }
    else
        combat->box_enemy.top = 0;
}

void display_combat(hub_t *hub, combat_t *combat, window_t *window_s)
{
    sfVector2f pos;

    pos.x = -180;
    pos.y = -40;
    sfSprite_setPosition(hub->inventory->menu, pos);
    sfRenderWindow_drawSprite(window_s->window, combat->background, NULL);
    sfRenderWindow_drawSprite(window_s->window, hub->inventory->menu, NULL);
    sfRenderWindow_drawSprite(\
    window_s->window, combat->player->sprite, NULL);
    sfRenderWindow_drawSprite(window_s->window, combat->enemy->sprite, NULL);
    sfRenderWindow_drawSprite(\
    window_s->window, combat->enemy_pv->sprite, NULL);
    sfRenderWindow_drawSprite(\
    window_s->window, combat->player_pv->sprite, NULL);
    display_condition(hub);
    sfRenderWindow_display(window_s->window);
}