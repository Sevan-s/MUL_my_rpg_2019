/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void start_position(start_t *start)
{
    start->position1.x = 770;
    start->position1.y = 200;
    sfSprite_setPosition(start->sprite_button, start->position1);
    sfSprite_setPosition(start->sprite_start_hover, start->position1);
    start->position2.x = 770;
    start->position2.y = 750;
    sfSprite_setPosition(start->sprite_button_exit, start->position2);
    sfSprite_setPosition(start->sprite_exit_hover, start->position2);
}

void start_sprite_next(start_t *start)
{
    start->texture3 = sfTexture_createFromFile(\
    "asset/texture/button/exit.png", NULL);
    start->sprite_button_exit = sfSprite_create();
    sfSprite_setTexture(start->sprite_button_exit, start->texture3, \
    sfTrue);
    start->music = sfMusic_createFromFile("asset/music/menu_music.ogg");
    sfMusic_play(start->music);
    sfMusic_setVolume(start->music, 30);
    start->sound = sfMusic_createFromFile("asset/music/sound.ogg");
    sfMusic_setVolume(start->sound, 0);
}

void start_sprite(start_t *start)
{
    start->texture1 = sfTexture_createFromFile(\
    "asset/texture/menu_start.jpg", NULL);
    start->sprite_start = sfSprite_create();
    sfSprite_setTexture(start->sprite_start, start->texture1, sfTrue);
    start->texture2 = sfTexture_createFromFile(\
    "asset/texture/button/start.png", NULL);
    start->sprite_button = sfSprite_create();
    sfSprite_setTexture(start->sprite_button, start->texture2, sfTrue);
    start->texture_start_hover = sfTexture_createFromFile(\
    "asset/texture/button/start_hover.png", NULL);
    start->sprite_start_hover = sfSprite_create();
    sfSprite_setTexture(start->sprite_start_hover,\
    start->texture_start_hover, sfTrue);
    start->texture_exit_hover = sfTexture_createFromFile(\
    "asset/texture/button/exit_hover.png", NULL);
    start->sprite_exit_hover = sfSprite_create();
    sfSprite_setTexture(start->sprite_exit_hover,\
    start->texture_exit_hover, sfTrue);
    start_sprite_next(start);
}

int menu_start_hover(start_t *start, window_t *manage_window)
{
    sfVector2i position = (sfVector2i){0, 0};

    position = sfMouse_getPositionRenderWindow(manage_window->window);
    if (position.x >= 770 && position.x <= 1090 && start->htp_stat == 0) {
        if (position.y >= 200 && position.y <= 360) {
            sfRenderWindow_drawSprite(manage_window->window, \
            start->sprite_start_hover, NULL);
        }
        if (position.y >= 750 && position.y <= 910) {
            sfRenderWindow_drawSprite(manage_window->window, \
            start->sprite_exit_hover, NULL);
            return (1);
        }
    }
    return (0);
}

void menu_start(start_t *start, window_t *manage_window)
{
    if (start->htp_stat == 0) {
        sfRenderWindow_drawSprite(manage_window->window, \
        start->sprite_start, NULL);
        sfRenderWindow_drawSprite(manage_window->window, \
        start->sprite_button, NULL);
        sfRenderWindow_drawSprite(manage_window->window, \
        start->sprite_button_exit, NULL);
        sfRenderWindow_drawSprite(manage_window->window, \
        start->htp->sprite, NULL);
        menu_start_hover(start, manage_window);
    }
    else {
        sfRenderWindow_drawSprite(manage_window->window, \
        start->sprite_start, NULL);
        sfRenderWindow_drawText(manage_window->window, \
        start->htp_text, NULL);
    }
}