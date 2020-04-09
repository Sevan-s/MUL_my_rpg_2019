/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/csfml.h"

void move_rectangle(sfIntRect *rect)
{
    rect->left -= 38;
    if (rect->left <= 0)
        rect->left = 270;
}

void move_sprite_ennemy(enemy_t *enemy)
{
    if (enemy->position.x > -100 && enemy->position.x < 250)
        enemy->position.x += 2;
    else if (enemy->position.x > 250 && enemy->position.x < 600) {
        enemy->position.x += 2;
        enemy->position.y -= 1;
    }
}

void move_sprite_ennemy_next(enemy_t *enemy)
{
    if (enemy->position.x > 600 && enemy->position.x < 1220) {
        enemy->position.x += 2;
        enemy->position.y += 1.25;
    }
    else if (enemy->position.x > 1220 && enemy->position.x < 1700) {
        enemy->position.x += 2;
        enemy->position.y -= 1;
    }
}

void move_enemy(enemy_t *enemy)
{
    enemy->time1 = sfClock_getElapsedTime(enemy->clock1);
    enemy->seconds1 = enemy->time1.microseconds / 1000000.0;
    if (enemy->seconds1 > 0.04) {
        move_sprite_ennemy(enemy);
        move_sprite_ennemy_next(enemy);
        if (enemy->position.x > 1700 && enemy->position.x < 1920) {
            enemy->position.x += 2;
            enemy->position.y -= 0;
        }
        sfSprite_setPosition(enemy->sprite_enemy, enemy->position);
        move_rectangle(&enemy->rect1);
        sfClock_restart(enemy->clock1);
    }
}