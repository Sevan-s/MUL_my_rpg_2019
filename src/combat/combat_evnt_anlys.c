/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** combat_evnt_anlys.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void combat_buttons(hub_t *hub)
{
    if (hub->combat->turn == 1 && hub->inventory->state == 0) {
        combat_pause_click(hub->manage_window->event, \
        hub->manage_window, hub->start);
        cut_click(hub->manage_window, \
        hub->manage_window->event.mouseButton, hub->combat, hub);
        flee_click(hub->manage_window, \
        hub->manage_window->event.mouseButton, hub->combat);
        bag_click(hub->manage_window->event.mouseButton, \
        hub->inventory, hub->combat);
    }
    else if (hub->combat->turn == 1 && hub->inventory->state == 1)
        inventory_event(hub->inventory, hub, \
        hub->manage_window->event.mouseButton);
}

void combat_pause_click(sfEvent event, window_t *manage_window, \
start_t *start)
{
    if (event.mouseButton.x >= 270 && event.mouseButton.x <= 380)
        if (event.mouseButton.y >= 110 && event.mouseButton.y <= 230) {
            manage_window->scene = 2;
            sfMusic_play(start->pause);
        }
}

void cut_click(window_t *window_s, sfMouseButtonEvent event, \
combat_t *combat, hub_t *hub)
{
    if (event.x >= 20 && event.x <= 150)
        if (event.y >= 20 && event.y <= 100) {
            cut(hub, window_s, combat);
            combat->turn = -1;
        }
}

void flee_click(window_t *window_s, sfMouseButtonEvent event, combat_t *combat)
{
    if (event.x >= 20 && event.x <= 210)
        if (event.y >= 150 && event.y <= 200) {
            window_s->scene = 1;
            window_s->scene_save = 1;
            if (combat->z_stunned == 0)
                combat->pv -= 20;
            combat->pv_e = 100;
        }
}

void bag_click(sfMouseButtonEvent event, \
inventory_t *inventory, combat_t *combat)
{
    if (event.x >= 250 && event.x <= 390)
        if (event.y >= 30 && event.y <= 80) {
            inventory->state = 1;
            sfSound_play(combat->search);
        }
}