/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_escape.c
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void manage_escape(hub_t *hub)
{
    if (hub->manage_window->scene == 1)
        manage_pause_Escape(hub->manage_window, hub->start, hub);
    else if (hub->manage_window->scene == 0 && hub->start->htp_stat == 1)
        hub->start->htp_stat = 0;
}