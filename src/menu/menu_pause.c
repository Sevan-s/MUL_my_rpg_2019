/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void pause_position(start_t *start)
{
    start->position3.x = 200;
    start->position3.y = 750;
    sfSprite_setPosition(start->sprite_continue, start->position3);
    start->position4.x = 1350;
    start->position4.y = 350;
    sfSprite_setPosition(start->sprite_button_start, start->position4);
    start->position5.x = 770;
    start->position5.y = 750;
    sfSprite_setPosition(start->sprite_exit, start->position5);
}

void pause_sprite(start_t *start)
{
    start->texture_4 = sfTexture_createFromFile(\
    "asset/texture/menu_pause.jpg", NULL);
    start->sprite_pause = sfSprite_create();
    sfSprite_setTexture(start->sprite_pause, start->texture_4, sfTrue);
    start->texture5 = sfTexture_createFromFile(\
    "asset/texture/button/start.png", NULL);
    start->sprite_continue = sfSprite_create();
    sfSprite_setTexture(start->sprite_continue, start->texture5, sfTrue);
    start->texture6 = sfTexture_createFromFile(\
    "asset/texture/button/continue.png", NULL);
    start->sprite_button_start = sfSprite_create();
    sfSprite_setTexture(start->sprite_button_start, \
    start->texture6, sfTrue);
    start->texture7 = sfTexture_createFromFile(\
    "asset/texture/button/exit.png", NULL);
    start->sprite_exit = sfSprite_create();
    sfSprite_setTexture(start->sprite_exit, start->texture7, sfTrue);
    start->pause = sfMusic_createFromFile("asset/music/pause_music.ogg");
    sfMusic_setVolume(start->pause, 30);
}

int menu_pause_hover(start_t *start, window_t *manage_window)
{
    sfVector2i position = (sfVector2i){0, 0};

    position = sfMouse_getPositionRenderWindow(manage_window->window);
    if (position.y >= 750 && position.y <= 910) {
        if (position.x >= 770 && position.x <= 1090) {
            sfSprite_setPosition(start->sprite_exit_hover, start->position5);
            sfRenderWindow_drawSprite(manage_window->window, \
            start->sprite_exit_hover, NULL);
            return (1);
        }
        if (position.x >= 200 && position.x <= 520) {
            sfSprite_setPosition(start->sprite_start_hover, start->position3);
            sfRenderWindow_drawSprite(manage_window->window, \
            start->sprite_start_hover, NULL);
        }
    }
    return (0);
}

int manage_pause_menu_click(sfMouseButtonEvent event, \
window_t *manage_window, start_t *start, hub_t *hub)
{
    if (event.x >= 1350 && event.x <= 1500) {
        if (event.y >= 350 && event.y <= 500) {
            manage_window->scene = manage_window->scene_save;
            sfMusic_stop(start->pause);
            sfMusic_play(manage_window->game);
        }
    }
    if (event.y >= 750 && event.y <= 910) {
        if (event.x >= 770 && event.x <= 1090)
            return (1);
        if (event.x >= 200 && event.x <= 520) {
            manage_window->scene = 0;
            sfMusic_stop(start->pause);
            destroy_all(hub);
            initialization(hub);
            inventory_ini(hub->inventory, hub->character);
            sfMusic_play(start->music);
        }
    }
    return (0);
}

void menu_pause(start_t *start, window_t *manage_window)
{
    sfMusic_setLoop(start->pause, sfTrue);
    sfRenderWindow_drawSprite(manage_window->window, \
    start->sprite_pause, NULL);
    sfRenderWindow_drawSprite(manage_window->window, \
    start->sprite_continue, NULL);
    sfRenderWindow_drawSprite(manage_window->window, \
    start->sprite_button_start, NULL);
    sfRenderWindow_drawSprite(manage_window->window, \
    start->sprite_exit, NULL);
    menu_pause_hover(start, manage_window);
}