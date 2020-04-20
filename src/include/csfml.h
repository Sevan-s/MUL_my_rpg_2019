/*
** EPITECH PROJECT, 2019
** csfml.h
** File description:
** Contains the include of CSFML
*/

#ifndef CSFML
#define CSFML

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include "my.h"
#include "struct.h"

sfTexture *sfTexture_createFromFile(const char *filename, \
const sfIntRect *area);
sfSprite *sfSprite_create(void);
void sfSprite_setTexture(sfSprite *sprite, const sfTexture *texture, \
sfBool resetRect);
void sfSprite_setTextureRect(sfSprite *sprite, sfIntRect rectangle);
sfClock *sfClock_create(void);
sfTime sfClock_getElapsedTime(const sfClock *clock);
sfTime sfClock_restart(sfClock *clock);
void sfSprite_setPosition(sfSprite *sprite, sfVector2f position);
void sfSprite_destroy(sfSprite *sprite);
void sfTexture_destroy(sfTexture *texture);
void 	sfMusic_setLoop (sfMusic *music, sfBool loop);
sfMusic *sfMusic_createFromFile(const char *filename);
void sfMusic_play(sfMusic *music);
void sfMusic_destroy(sfMusic *music);

#endif