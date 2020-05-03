/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory_event.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void inventory_event(inventory_t *inventory, hub_t *hub, \
sfMouseButtonEvent event)
{
    if (event.x >= 0 && event.x <= 75)
        if (event.y >= 0 && event.y <= 60)
            inventory->state = 0;
    if (event.x >= 70 && event.x <= 120 && hub->manage_window->scene == 3)
        if (event.y >= 165 && event.y <= 227 && inventory->grenade_nb > 0)
            grenade(inventory, hub);
    if (event.x >= 30 && event.x <= 120 && hub->manage_window->scene == 3)
        if (event.y >= 70 && event.y <= 140 && inventory->pistol_nb > 0)
            pistol(inventory, hub);
    detect_medic(inventory, hub, event);
    if (event.x >= 215 && event.x <= 380 && hub->manage_window->scene == 3)
        if (event.y >= 180 && event.y <= 210 && inventory->throw_knife_nb > 0)
            throw_knife(inventory, hub);
}

void grenade(inventory_t *inventory, hub_t *hub)
{
    sfSound_play(inventory->grenade_sound);
    inventory->grenade_nb -= 1;
    hub->combat->pv_e = 0;
    hub->combat->box_enemy_pv.width = 0;
    sfSprite_setTextureRect(hub->combat->enemy_pv->sprite, \
    hub->combat->box_enemy_pv);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->combat->enemy_pv->sprite, NULL);
    hub->combat->turn = -1;
}

void pistol(inventory_t *inventory, hub_t *hub)
{
    sfSound_play(inventory->pistol_sound);
    inventory->pistol_nb -= 1;
    hub->combat->pv_e -= 30;
    hub->combat->box_enemy_pv.width -= 249;
    sfSprite_setTextureRect(hub->combat->enemy_pv->sprite, \
    hub->combat->box_enemy_pv);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->combat->enemy_pv->sprite, NULL);
    hub->combat->turn = -1;
}

void medic(inventory_t *inventory, hub_t *hub)
{
    sfSound_play(inventory->medic_sound);
    inventory->medic_nb -= 1;
    if (hub->combat->pv <= 60)
        hub->combat->pv += 40;
    else if (hub->combat->pv > 60)
        hub->combat->pv = 100;
    if (hub->manage_window->scene == 3) {
        if (hub->combat->box_player_pv.width <= 498)
            hub->combat->box_player_pv.width += 332;
        else if (hub->combat->box_player_pv.width > 498)
            hub->combat->box_player_pv.width = 830;
        sfSprite_setTextureRect(hub->combat->player_pv->sprite, \
        hub->combat->box_player_pv);
        sfRenderWindow_drawSprite(hub->manage_window->window, \
        hub->combat->player_pv->sprite, NULL);
        hub->combat->turn = -1;
    }
}

void throw_knife(inventory_t *inventory, hub_t *hub)
{
    sfSound_play(inventory->throw_sound);
    inventory->throw_knife_nb -= 1;
    hub->combat->z_stunned = 2;
    hub->combat->pv_e -= 10;
    hub->combat->box_enemy_pv.width -= 83;
    sfSprite_setTextureRect(hub->combat->enemy_pv->sprite, \
    hub->combat->box_enemy_pv);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->combat->enemy_pv->sprite, NULL);
    hub->combat->turn = -1;
}