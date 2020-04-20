/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void start_position(start_t *start)
{
    start->position1.x = 770;
    start->position1.y = 200;
    sfSprite_setPosition(start->sprite_button, start->position1);
    start->position2.x = 770;
    start->position2.y = 750;
    sfSprite_setPosition(start->sprite_button_exit, start->position2);
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
    start->texture3 = sfTexture_createFromFile(\
    "asset/texture/button/exit.png", NULL);
    start->sprite_button_exit = sfSprite_create();
    sfSprite_setTexture(start->sprite_button_exit, start->texture3,\
    sfTrue);
    start->music = sfMusic_createFromFile("asset/music/menu_music.ogg");
    sfMusic_play(start->music);
    start->sound = sfMusic_createFromFile("asset/music/sound.ogg");
}

void menu_start(start_t *start, window_t *manage_window)
{
    sfRenderWindow_drawSprite(manage_window->window,\
    start->sprite_start, NULL);
    sfRenderWindow_drawSprite(manage_window->window,\
    start->sprite_button, NULL);
    sfRenderWindow_drawSprite(manage_window->window,\
    start->sprite_button_exit, NULL);
}