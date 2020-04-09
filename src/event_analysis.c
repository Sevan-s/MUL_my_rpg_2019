/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

int analyse_events(sfEvent event, window_t *manag_window, start_t *start)
{
    int result = 0;

    while (sfRenderWindow_pollEvent(manag_window->window, &event)) {
        switch (event.type) {
        case sfEvtMouseButtonPressed:
            result = button_click_detection(manag_window, start, event);
            break;
        case sfEvtClosed:
            return (1);
        default:
            break;
        }
        if (event.key.code == sfKeyEscape && manag_window->scene == 1) {
            manage_pause_Escape(manag_window, start);
        }
    }
    return (result);
}

int button_click_detection(window_t *manag_window, start_t *start,\
sfEvent event)
{
    int result = 0;

    if (manag_window->scene == 0)
        result = manage_mouse_click(event.mouseButton,\
        manag_window, start);
    if (manag_window->scene == 1)
        manage_pause_click(event.mouseButton, manag_window, start);
    if (manag_window->scene == 2)
        result = manage_pause_menu_click(event.mouseButton,\
        manag_window, start);
    return (result);
}

void manage_pause_Escape(window_t *manag_window, start_t *start)
{
    manag_window->scene = 2;
    sfMusic_stop(manag_window->game);
    sfMusic_play(start->pause);
}

void manage_pause_click(sfMouseButtonEvent event, window_t *manag_window,\
start_t *start)
{
    if (event.x >= 20 && event.x <= 90) {
        if (event.y >= 20 && event.y <= 90) {
            manag_window->scene = 2;
            sfMusic_stop(manag_window->game);
            sfMusic_play(start->pause);
        }
    }
}

int manage_mouse_click(sfMouseButtonEvent event, window_t *manag_window,\
start_t *start)
{
    if (event.x >= 770 && event.x <= 1090) {
        if (event.y >= 200 && event.y <= 360) {
            manag_window->scene = 1;
            sfMusic_stop(start->music);
            sfMusic_play(start->sound);
            sfMusic_play(manag_window->game);
        }
        if (event.y >= 750 && event.y <= 910)
            return (1);
    }
    return (0);
}
