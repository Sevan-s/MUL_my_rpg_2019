/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void enemy_sprite(enemy_t *enemy, window_t *manag_window, int nb)
{
    enemy->sprite_enemy = sfSprite_create();
    sfSprite_setTexture(enemy->sprite_enemy,\
    manag_window->texture_enemy, sfTrue);
    enemy->clock1 = sfClock_create();
    enemy->rect1 = (sfIntRect){280, 0, 40, 90};
    sfSprite_setTextureRect(enemy->sprite_enemy, enemy->rect1);
    enemy->position = (sfVector2f){(-1000 + nb), 500};
    sfSprite_setPosition(enemy->sprite_enemy, enemy->position);
}

void enemy_insertion(list_t *liste, window_t *manag_window, int nb)
{
    enemy_t *new = malloc(sizeof(enemy_t));

    if (!liste || !new)
        write(2, "Error, malloc\n", 15);
    enemy_sprite(new, manag_window, nb);
    new->next = liste->first;
    liste->first = new;
}

list_t *enemy_ini(window_t *manag_window)
{
    list_t *list = malloc(sizeof(list_t));
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (!list || !enemy)
        write(2, "Error, malloc\n", 15);
    manag_window->texture_enemy = sfTexture_createFromFile\
    ("asset/enemy_droidB1.png", NULL);
    enemy_sprite(enemy, manag_window, 0);
    enemy->next = NULL;
    list->first = enemy;
    return (list);
}

void background_game_def(background_t *background)
{
    background->texture_background_game = sfTexture_createFromFile(\
    "asset/tower_defense_niv1.png", NULL);
    background->sprite_background_game = sfSprite_create();
    sfSprite_setTexture(background->sprite_background_game,\
    background->texture_background_game, sfTrue);
    background->texture_pause_game = sfTexture_createFromFile(\
    "asset/pause_game.png", NULL);
    background->sprite_pause_game = sfSprite_create();
    sfSprite_setTexture(background->sprite_pause_game,\
    background->texture_pause_game, sfTrue);
}

void game(window_t *manag_window, background_t *background,\
list_t *list)
{
    enemy_t *current = list->first;

    sfRenderWindow_drawSprite(manag_window->window,\
    background->sprite_background_game, NULL);
    sfRenderWindow_drawSprite(manag_window->window,\
    background->sprite_pause_game, NULL);
}