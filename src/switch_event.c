/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** switch_event.c
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

int switch_event(hub_t *hub, int *result)
{
    switch (hub->manage_window->event.type) {
        case sfEvtMouseButtonPressed:
            *result = button_click_detection(hub);
            break;
        case sfEvtClosed:
            return (1);
        default:
            break;
    }
    if (hub->manage_window->event.key.code == sfKeyEscape)
        manage_escape(hub);
    return (0);
}