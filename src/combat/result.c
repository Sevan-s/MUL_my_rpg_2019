/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** result.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

int result_cmb(int outcome, int result, window_t *window_s, hub_t *hub)
{
    sfMusic_stop(hub->combat->music);
    if (window_s->scene == 3) {
        window_s->scene = 1;
        window_s->scene_save = 1;
    }
    if (outcome == 2 || hub->combat->pv <= 0) {
        window_s->scene = 0;
        sfMusic_stop(hub->start->pause);
        destroy_all(hub);
        initialization(hub);
        inventory_ini(hub->inventory, hub->character);
        sfMusic_play(hub->start->music);
    }
    if (result != 0)
        return (1);
    if (outcome == 1)
        reward(hub->inventory);
    return (0);
}