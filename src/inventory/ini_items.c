/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ini_items.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void init_grenade(inventory_t *inventory, sfVector2f character)
{
    inventory->grenade_nb = 1;
    inventory->grenade->texture = sfTexture_createFromFile(\
    "asset/texture/inventory/grenade.png", NULL);
    inventory->grenade->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->grenade->sprite, \
    inventory->grenade->texture, sfTrue);
    inventory->grenade->pos.x = 20 + character.x - 450;
    inventory->grenade->pos.y = 130 + character.y - 450;
    inventory->grenade->size.x = 0.4;
    inventory->grenade->size.y = 0.4;
    sfSprite_setPosition(inventory->grenade->sprite, inventory->grenade->pos);
    sfSprite_setScale(inventory->grenade->sprite, inventory->grenade->size);
    inventory->grenade_sound = sfSound_create();
    inventory->grenade_buffer = sfSoundBuffer_createFromFile(\
    "asset/music/grenade.ogg");
    sfSound_setBuffer(inventory->grenade_sound, inventory->grenade_buffer);
}

void init_pistol(inventory_t *inventory, sfVector2f character)
{
    inventory->pistol_nb = 1;
    inventory->pistol->texture = sfTexture_createFromFile(\
    "asset/texture/inventory/pistol.png", NULL);
    inventory->pistol->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->pistol->sprite, \
    inventory->pistol->texture, sfTrue);
    inventory->pistol->pos.x = 20 + character.x - 450;
    inventory->pistol->pos.y = 70 + character.y - 450;
    inventory->pistol->size.x = 0.15;
    inventory->pistol->size.y = 0.15;
    sfSprite_setPosition(inventory->pistol->sprite, inventory->pistol->pos);
    sfSprite_setScale(inventory->pistol->sprite, inventory->pistol->size);
    inventory->pistol_sound = sfSound_create();
    inventory->pistol_buffer = sfSoundBuffer_createFromFile(\
    "asset/music/pistol.ogg");
    sfSound_setBuffer(inventory->pistol_sound, inventory->pistol_buffer);
}

void init_medic(inventory_t *inventory, sfVector2f character)
{
    inventory->medic_nb = 3;
    inventory->medic->texture = sfTexture_createFromFile(\
    "asset/texture/inventory/medic.png", NULL);
    inventory->medic->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->medic->sprite, \
    inventory->medic->texture, sfTrue);
    inventory->medic->pos.x = 250 + character.x - 500;
    inventory->medic->pos.y = 60 + character.y - 450;
    inventory->medic->size.x = 0.05;
    inventory->medic->size.y = 0.05;
    sfSprite_setPosition(inventory->medic->sprite, inventory->medic->pos);
    sfSprite_setScale(inventory->medic->sprite, inventory->medic->size);
    inventory->medic_sound = sfSound_create();
    inventory->medic_buffer = sfSoundBuffer_createFromFile(\
    "asset/music/medic.ogg");
    sfSound_setBuffer(inventory->medic_sound, inventory->medic_buffer);
}

void init_throw(inventory_t *inventory, sfVector2f character)
{
    inventory->throw_knife_nb = 1;
    inventory->throw_knife->texture = sfTexture_createFromFile(\
    "asset/texture/inventory/throw_knife.png", NULL);
    inventory->throw_knife->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->throw_knife->sprite, \
    inventory->throw_knife->texture, sfTrue);
    inventory->throw_knife->pos.x = 200 + character.x - 480;
    inventory->throw_knife->pos.y = 170 + character.y - 450;
    inventory->throw_knife->size.x = 0.12;
    inventory->throw_knife->size.y = 0.12;
    sfSprite_setPosition(inventory->throw_knife->sprite, \
    inventory->throw_knife->pos);
    sfSprite_setScale(inventory->throw_knife->sprite, \
    inventory->throw_knife->size);
    inventory->throw_sound = sfSound_create();
    inventory->throw_buffer = sfSoundBuffer_createFromFile(\
    "asset/music/throw_knife.ogg");
    sfSound_setBuffer(inventory->throw_sound, inventory->throw_buffer);
}

void back_ini(inventory_t *inventory, sfVector2f character)
{
    inventory->text_menu = sfTexture_createFromFile(\
    "asset/texture/inventory/menu.png", NULL);
    inventory->menu = sfSprite_create();
    sfSprite_setTexture(inventory->menu, \
    inventory->text_menu, sfTrue);
    inventory->pos_menu.x = -200 + character.x - 550;
    inventory->pos_menu.y = -50 + character.y - 470;
    sfSprite_setPosition(inventory->menu, inventory->pos_menu);
    inventory->back->texture = sfTexture_createFromFile(\
    "asset/texture/inventory/back.png", NULL);
    inventory->back->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->back->sprite, \
    inventory->back->texture, sfTrue);
    inventory->back->pos.x = 0;
    inventory->back->pos.y = -10;
    inventory->back->size.x = 0.05;
    inventory->back->size.y = 0.05;
    sfSprite_setPosition(inventory->back->sprite, inventory->back->pos);
    sfSprite_setScale(inventory->back->sprite, inventory->back->size);
}