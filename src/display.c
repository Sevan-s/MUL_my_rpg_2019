/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void move_rect_fire(hub_t *hub)
{
    hub->effects->rect_fire.left += 64;
    sfSprite_setTextureRect(hub->effects->sprite_fire,
    hub->effects->rect_fire);
    if (hub->effects->rect_fire.left >= 448) {
        hub->effects->rect_fire.left = 0;
        hub->effects->rect_fire.top += 128;
        sfSprite_setTextureRect(hub->effects->sprite_fire,
        hub->effects->rect_fire);
    }
    if (hub->effects->rect_fire.top >= 384) {
        hub->effects->rect_fire.top = 0;
        sfSprite_setTextureRect(hub->effects->sprite_fire,
        hub->effects->rect_fire);
    }
}

void second_game_display(hub_t *hub)
{
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->effects->sprite_fire, NULL);
    inventory_display(hub->manage_window, hub->inventory, hub);
    if (hub->quests->quests_status == 1)
        display_quest(hub);
    move_rect_fire(hub);
}

void game_display(hub_t *hub)
{
    display_view(hub);
    sfText_setString(hub->inventory->pv_text, nbr_in_str(hub->combat->pv));
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->background->sprite_background_game, NULL);
    pause_button_position(hub);
    sfSprite_setPosition(hub->effects->sprite_rain, \
    hub->effects->rain_position);
    sfSprite_setPosition(hub->background->sprite_pause_game, \
    hub->background->position_pause);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->character->sprite_character, NULL);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->effects->sprite_rain, NULL);
    clock_parralax(hub);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->background->sprite_pause_game, NULL);
    second_game_display(hub);
}

void display_view(hub_t *hub)
{
    hub->character->position_character = \
    sfSprite_getPosition(hub->character->sprite_character);
    sfFloatRect rect = {0, 0, 900, 900};
    hub->background->view = sfView_createFromRect(rect);
    sfView_setCenter(hub->background->view, hub->character->position_character);
    sfRenderWindow_setView(hub->manage_window->window, hub->background->view);
}

void pause_button_position(hub_t *hub)
{
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->pnj->sprite_pnj, NULL);
    sfRenderWindow_drawSprite(hub->manage_window->window, \
    hub->pnj->sprite_pnj2, NULL);
    hub->background->position_pause.x =  \
    hub->character->position_character.x + 350;
    hub->background->position_pause.y = \
    hub->character->position_character.y - 450;
}