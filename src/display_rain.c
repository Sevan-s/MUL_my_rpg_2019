/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void init_parrallax(hub_t *hub)
{
    hub->effects->rain_clock = sfClock_create();
    hub->effects->texture_rain = \
    sfTexture_createFromFile("asset/texture/rain.png", NULL);
    hub->effects->sprite_rain = sfSprite_create();
    sfSprite_setTexture(hub->effects->sprite_rain, \
    hub->effects->texture_rain, sfTrue);
    hub->effects->rain_position = (sfVector2f){-1080, -2000};
    sfSprite_setPosition(hub->effects->sprite_rain, \
    hub->effects->rain_position);
}

void clock_parralax(hub_t *hub)
{
    float seconds;

    hub->effects->rain_time = \
    sfClock_getElapsedTime(hub->effects->rain_clock).microseconds;
    seconds = hub->effects->rain_time / 1000;
    if (seconds > 1) {
        sfSprite_move(hub->effects->sprite_rain, (sfVector2f){-1, +3});
        hub->effects->rain_position = sfSprite_getPosition \
        (hub->effects->sprite_rain);
        if (hub->effects->rain_position.y >= 0)
            hub->effects->rain_position = (sfVector2f){-100, -1000};
        sfClock_restart(hub->effects->rain_clock);
    }
}