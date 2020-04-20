/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void destroy_start(start_t *start)
{
    sfMusic_stop(start->sound);
    sfMusic_destroy(start->sound);
    sfMusic_stop(start->pause);
    sfMusic_destroy(start->pause);
    sfMusic_stop(start->music);
    sfMusic_destroy(start->music);
    sfSprite_destroy(start->sprite_start);
    sfSprite_destroy(start->sprite_button);
    sfSprite_destroy(start->sprite_button_exit);
    sfSprite_destroy(start->sprite_pause);
    sfSprite_destroy(start->sprite_continue);
    sfSprite_destroy(start->sprite_button_start);
    sfSprite_destroy(start->sprite_exit);
    sfTexture_destroy(start->texture1);
    sfTexture_destroy(start->texture2);
    sfTexture_destroy(start->texture3);
    sfTexture_destroy(start->texture_4);
    sfTexture_destroy(start->texture5);
    sfTexture_destroy(start->texture6);
    sfTexture_destroy(start->texture7);
}

void destroy_background(background_t *background)
{
    sfSprite_destroy(background->sprite_background_game);
    sfTexture_destroy(background->texture_background_game);
    sfSprite_destroy(background->sprite_pause_game);
    sfTexture_destroy(background->texture_pause_game);
}

void destroy_window(window_t *manage_window)
{
    sfMusic_stop(manage_window->game);
    sfMusic_destroy(manage_window->game);
    sfRenderWindow_close(manage_window->window);
    sfRenderWindow_destroy(manage_window->window);
}

void destroy_all(hub_t *hub)
{
    destroy_window(hub->manage_window);
    destroy_background(hub->background);
    destroy_start(hub->start);
}