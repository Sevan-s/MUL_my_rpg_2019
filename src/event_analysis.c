/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

int analyse_events(hub_t *hub)
{
    int result = 0;

    while (sfRenderWindow_pollEvent(hub->manage_window->window,\
    &hub->manage_window->event)) {
        switch (hub->manage_window->event.type) {
        case sfEvtMouseButtonPressed:
            result = button_click_detection(hub);
            break;
        case sfEvtClosed:
            return (1);
        default:
            break;
        }
        if (hub->manage_window->event.key.code == sfKeyEscape && hub->manage_window->scene == 1) {
            manage_pause_Escape(hub->manage_window, hub->start);
        }
    }
    return (result);
}

int button_click_detection(hub_t *hub)
{
    int result = 0;

    if (hub->manage_window->scene == 0)
        result = manage_mouse_click(hub->manage_window->event.mouseButton,\
        hub->manage_window, hub->start);
    if (hub->manage_window->scene == 1)
        manage_pause_click(hub->manage_window->event.mouseButton,\
        hub->manage_window, hub->start);
    if (hub->manage_window->scene == 2)
        result = manage_pause_menu_click(hub->manage_window->event.\
        mouseButton, hub->manage_window, hub->start);
    return (result);
}

void manage_pause_Escape(window_t *manage_window, start_t *start)
{
    manage_window->scene = 2;
    sfMusic_stop(manage_window->game);
    sfMusic_play(start->pause);
}

void manage_pause_click(sfMouseButtonEvent event, window_t *manage_window,\
start_t *start)
{
    if (event.x >= 20 && event.x <= 90) {
        if (event.y >= 20 && event.y <= 90) {
            manage_window->scene = 2;
            sfMusic_stop(manage_window->game);
            sfMusic_play(start->pause);
        }
    }
}

int manage_mouse_click(sfMouseButtonEvent event, window_t *manage_window,\
start_t *start)
{
    if (event.x >= 770 && event.x <= 1090) {
        if (event.y >= 200 && event.y <= 360) {
            manage_window->scene = 1;
            sfMusic_stop(start->music);
            sfMusic_play(start->sound);
            sfMusic_play(manage_window->game);
        }
        if (event.y >= 750 && event.y <= 910)
            return (1);
    }
    return (0);
}
