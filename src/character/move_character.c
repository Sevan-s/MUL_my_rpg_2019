/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** function
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void move_character(hub_t *hub)
{
    float seconds;

    hub->character->time = \
    sfClock_getElapsedTime(hub->character->clock).microseconds;
    seconds = hub->character->time / 1000;
    if (seconds >= 1) {
        move_character_left(hub);
        move_character_right(hub);
        move_character_down(hub);
        move_character_up(hub);
        sfSprite_setTextureRect(hub->character->sprite_character,
        hub->character->rect_character);
        sfClock_restart(hub->character->clock);
    }
}

int move_character_left(hub_t *hub)
{
    static int i = 0;

    if (hub->character->position_character.x - 5 < 0)
        return (0);
    if (hub->character->map[hub->character->y]\
    [(hub->character->x - 1)] == '1')
        return (0);
    if (hub->manage_window->event.key.code == sfKeyQ) {
        sfSprite_move(hub->character->sprite_character, (sfVector2f){-4, 0});
        hub->character->rect_character.top = 56.25;
        set_pnj_clock(hub->character);
        i += 4;
        if (i >= 32) {
            hub->character->x -= 1;
            i = 0;
        }
    }
    return (0);
}

int move_character_right(hub_t *hub)
{
    static int i = 0;

    if (hub->character->position_character.x + 60 > 1920)
        return (0);
    if (hub->character->map[hub->character->y]\
    [(hub->character->x + 1)] == '1')
        return (0);
    if (hub->manage_window->event.key.code == sfKeyD) {
        hub->character->rect_character.top = 112.5;
        sfSprite_move(hub->character->sprite_character, (sfVector2f){4, 0});
        sfSprite_setTextureRect(hub->character->sprite_character,
        hub->character->rect_character);
        set_pnj_clock(hub->character);
        i += 4;
        if (i >= 32) {
            hub->character->x += 1;
            i = 0;
        }
    }
    return (0);
}

int move_character_down(hub_t *hub)
{
    static int i = 0;

    if (hub->character->position_character.y + 135 > 1080)
        return (0);
    if (hub->character->map[(hub->character->y + 1)]\
    [hub->character->x] == '1')
        return (0);
    if (hub->manage_window->event.key.code == sfKeyS) {
        hub->character->rect_character.top = 0;
        sfSprite_move(hub->character->sprite_character, (sfVector2f){0, 5});
        sfSprite_setTextureRect(hub->character->sprite_character,
        hub->character->rect_character);
        set_pnj_clock(hub->character);
        i += 5;
        if (i >= 32) {
            hub->character->y += 1;
            i = 0;
        }
    }
    return (0);
}

int move_character_up(hub_t *hub)
{
    static int i = 0;

    if (hub->character->position_character.y - 5 <= 0)
        return (0);
    if (hub->character->map[(hub->character->y - 1)]\
    [hub->character->x] == '1')
        return (0);
    if (hub->manage_window->event.key.code == sfKeyZ) {
        hub->character->rect_character.top = 168.75;
        sfSprite_move(hub->character->sprite_character, (sfVector2f){0, -5});
        sfSprite_setTextureRect(hub->character->sprite_character,
        hub->character->rect_character);
        set_pnj_clock(hub->character);
        i += 5;
        if (i >= 32) {
            hub->character->y -= 1;
            i = 0;
        }
    }
    return (0);
}