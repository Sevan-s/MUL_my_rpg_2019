/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** combat_core.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void core(hub_t *hub, int *result, int *outcome, sfClock *z_move)
{
    static float sec = 0;
    static int evnt = 0;

    evnt++;
    if (evnt == 1) {
        hub->inventory->progress += 25;
    }
    *result = analyse_events(hub);
    hub->combat->time = sfClock_getElapsedTime(z_move);
    sec = hub->combat->time.microseconds / 1000000.0;
    if (hub->combat->turn == -1 && sec >= 3.5 && hub->combat->pv_e > 0) {
        zombie_attack(hub->manage_window, hub->combat);
        sfClock_restart(z_move);
    }
    animate(hub->combat, hub->manage_window);
    display_combat(hub, hub->combat, hub->manage_window);
    *outcome = check_life(hub->combat);
}

void display_condition(hub_t *hub)
{
    if (hub->inventory->state == 0) {
        sfRenderWindow_drawSprite(\
        hub->manage_window->window, hub->combat->cut->sprite, NULL);
        sfRenderWindow_drawSprite(\
        hub->manage_window->window, hub->combat->flee->sprite, NULL);
        sfRenderWindow_drawSprite(\
        hub->manage_window->window, hub->combat->bag->sprite, NULL);
        sfRenderWindow_drawSprite(\
        hub->manage_window->window, hub->combat->pause->sprite, NULL);
    }
    else
        inventory_display(hub->manage_window, hub->inventory, hub);
}