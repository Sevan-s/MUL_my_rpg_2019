/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void display_parameter(window_t *manage_window)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    manage_window->window = sfRenderWindow_create(video_mode,
    "My_RPG", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(manage_window->window, 60);
}

void initialization(hub_t *hub)
{
    hub->manage_window->scene = 0;
    hub->manage_window->scene_save = 0;
    hub->combat->check = 0;
    hub->start->htp_stat = 0;
    display_parameter(hub->manage_window);
    start_sprite(hub->start);
    start_position(hub->start);
    pause_sprite(hub->start);
    pause_position(hub->start);
    htp_ini(hub->start);
    hub->combat->pv = 70;
    hub->combat->pv_e = 0;
    hub->manage_window->game = sfMusic_createFromFile\
    ("asset/music/game_music.ogg");
    sfMusic_setLoop(hub->manage_window->game, sfTrue);
    sfMusic_setVolume(hub->manage_window->game, 50);
    initialize_sec(hub);
}

void initialize_sec(hub_t *hub)
{
    background_game_ini(hub);
    initialization_character(hub->character);
    init_PNJ(hub);
    init_quests(hub);
    hub->quests->quest1 = 1;
    hub->quests->success = 0;
    hub->quests->quests_status = 1;
    hub->dialog->dialog_statut = 0;
    init_parrallax(hub);
    effects_game_ini(hub->effects);
    map_read(hub);
}

void menu(hub_t *hub, int *result)
{
    if (hub->manage_window->scene == 0)
        menu_start(hub->start, hub->manage_window);
    if (hub->manage_window->scene == 2)
        menu_pause(hub->start, hub->manage_window);
    if (hub->manage_window->scene == 3) {
        display_fight_view(hub);
        sfMusic_stop(hub->start->music);
        *result = combat_scene(hub->combat, hub->manage_window, hub);
    }
}

void game_loop(void)
{
    hub_t *hub = malloc(sizeof(hub_t));
    int result = 0;

    structuring_malloc(hub);
    initialization(hub);
    texture_dialog(hub);
    inventory_ini(hub->inventory, hub->character);
    while (sfRenderWindow_isOpen(hub->manage_window->window) && result == 0) {
        result = analyse_events(hub);
        sfRenderWindow_clear(hub->manage_window->window, sfBlack);
        menu(hub, &result);
        if (hub->manage_window->scene == 1) {
            hub->manage_window->scene_save = 1;
            game_display(hub);
            if (hub->dialog->dialog_statut == 1)
                pnj_dialog(hub);
        }
        sfRenderWindow_display(hub->manage_window->window);
    }
    destroy_all(hub);
}
