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

    while (sfRenderWindow_pollEvent(hub->manage_window->window, \
    &hub->manage_window->event)) {
        if (hub->manage_window->scene == 1) {
            move_character(hub);
            detect_pnj(hub);
        }
        if (switch_event(hub, &result) == 1)
            return (1);
    }
    return (result);
}

int button_click_detection(hub_t *hub)
{
    int result = 0;

    if (hub->manage_window->scene == 0)
        result = manage_mouse_click(hub->manage_window->event.mouseButton, \
        hub->manage_window, hub->start);
    if (hub->manage_window->scene == 1)
        manage_pause_click(hub->manage_window->event.mouseButton, \
        hub->manage_window, hub->start, hub);
    if (hub->manage_window->scene == 2)
        result = manage_pause_menu_click(hub->manage_window->event.\
        mouseButton, hub->manage_window, hub->start, hub);
    if (hub->manage_window->scene == 3)
        combat_buttons(hub);
    if (hub->manage_window->scene == 1)
        inventory_event(hub->inventory, hub, \
        hub->manage_window->event.mouseButton);
    return (result);
}

void manage_pause_Escape(window_t *manage_window, start_t *start, hub_t *hub)
{
    manage_window->scene = 2;
    sfMusic_stop(manage_window->game);
    sfView_setCenter(hub->background->view, (sfVector2f){960, 540});
    sfView_setSize(hub->background->view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(hub->manage_window->window, hub->background->view);
    sfMusic_play(start->pause);
}

void manage_pause_click(sfMouseButtonEvent event, window_t *manage_window, \
start_t *start, hub_t *hub)
{
    if (event.x >= 1750 && event.x <= 1900) {
        if (event.y >= 10 && event.y <= 100) {
            manage_window->scene = 2;
            sfMusic_stop(manage_window->game);
            sfView_setCenter(hub->background->view, (sfVector2f){960, 540});
            sfView_setSize(hub->background->view, (sfVector2f){1920, 1080});
            sfRenderWindow_setView(hub->manage_window->window, \
            hub->background->view);
            sfMusic_play(start->pause);
        }
    }
}

int manage_mouse_click(sfMouseButtonEvent event, window_t *manage_window, \
start_t *start)
{
    if (event.x >= 770 && event.x <= 1090 && start->htp_stat == 0) {
        if (event.y >= 200 && event.y <= 360) {
            manage_window->scene = 1;
            sfMusic_stop(start->music);
            sfMusic_play(start->sound);
            sfMusic_play(manage_window->game);
        }
        if (event.y >= 750 && event.y <= 910)
            return (1);
    }
    if (event.x >= 1600 && event.x <= 1900 && start->htp_stat == 0)
        if (event.y >= 0 && event.y <= 130)
            start->htp_stat = 1;
    return (0);
}
