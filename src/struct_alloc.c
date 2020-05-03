/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** struct_alloc.c
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void structuring_malloc(hub_t *hub)
{
    hub->manage_window = malloc(sizeof(window_t));
    hub->background = malloc(sizeof(background_t));
    hub->start = malloc(sizeof(start_t));
    hub->start->htp = malloc(sizeof(elem_t));
    hub->character = malloc(sizeof(character_t));
    hub->combat = malloc(sizeof(combat_t));
    hub->combat->enemy_pv = malloc(sizeof(elem_t));
    hub->combat->player_pv = malloc(sizeof(elem_t));
    hub->combat->player = malloc(sizeof(elem_t));
    hub->combat->enemy = malloc(sizeof(elem_t));
    hub->combat->cut = malloc(sizeof(elem_t));
    hub->combat->flee = malloc(sizeof(elem_t));
    hub->combat->bag = malloc(sizeof(elem_t));
    structuring_sec(hub);
}

void structuring_sec(hub_t *hub)
{
    hub->combat->pause = malloc(sizeof(elem_t));
    hub->inventory = malloc(sizeof(inventory_t));
    hub->inventory->back = malloc(sizeof(elem_t));
    hub->inventory->grenade = malloc(sizeof(elem_t));
    hub->inventory->throw_knife = malloc(sizeof(elem_t));
    hub->inventory->medic = malloc(sizeof(elem_t));
    hub->inventory->pistol = malloc(sizeof(elem_t));
    hub->inventory->progr = malloc(sizeof(elem_t));
    hub->effects = malloc(sizeof(effects_t));
    hub->pnj = malloc(sizeof(pnj_interaction_t));
    hub->dialog = malloc(sizeof(dialog_pnj_t));
    hub->quests = malloc(sizeof(quests_t));
}