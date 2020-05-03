/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_inventory.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void destroy_inventory(inventory_t *inventory)
{
    sfTexture_destroy(inventory->back->texture);
    sfTexture_destroy(inventory->grenade->texture);
    sfTexture_destroy(inventory->pistol->texture);
    sfTexture_destroy(inventory->medic->texture);
    sfTexture_destroy(inventory->throw_knife->texture);
    sfSprite_destroy(inventory->back->sprite);
    sfSprite_destroy(inventory->grenade->sprite);
    sfSprite_destroy(inventory->pistol->sprite);
    sfSprite_destroy(inventory->throw_knife->sprite);
    sfSprite_destroy(inventory->medic->sprite);
    sfSound_destroy(inventory->grenade_sound);
    sfSound_destroy(inventory->medic_sound);
    sfSound_destroy(inventory->pistol_sound);
    sfSound_destroy(inventory->throw_sound);
    sfSoundBuffer_destroy(inventory->grenade_buffer);
    sfSoundBuffer_destroy(inventory->medic_buffer);
    sfSoundBuffer_destroy(inventory->pistol_buffer);
    sfSoundBuffer_destroy(inventory->throw_buffer);
    sfTexture_destroy(inventory->text_menu);
    sfSprite_destroy(inventory->menu);
}