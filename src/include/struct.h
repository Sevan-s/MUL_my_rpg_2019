/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/
#ifndef STRUCT_H_
#define STRUCT_H_

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
#include "csfml.h"

typedef struct
{
    sfRenderWindow *window;
    sfEvent event;
    int scene;
    sfMusic *game;
    int scene_save;
} window_t;

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
} elem_t;

typedef struct
{
    int htp_stat;
    elem_t *htp;
    sfText *htp_text;
    sfFont *font;
    sfTexture *texture1;
    sfSprite *sprite_start;
    sfTexture *texture2;
    sfSprite *sprite_button;
    sfTexture *texture3;
    sfSprite *sprite_button_exit;
    sfSprite *sprite_start_hover;
    sfTexture *texture_start_hover;
    sfSprite *sprite_exit_hover;
    sfTexture *texture_exit_hover;
    sfVector2f position1;
    sfVector2f position2;
    sfMusic *music;
    sfTexture *texture_4;
    sfSprite *sprite_pause;
    sfTexture *texture5;
    sfSprite *sprite_continue;
    sfTexture *texture6;
    sfSprite *sprite_button_start;
    sfTexture *texture7;
    sfSprite *sprite_exit;
    sfVector2f position3;
    sfVector2f position4;
    sfVector2f position5;
    sfMusic *pause;
    sfMusic *sound;
} start_t;

typedef struct background
{
    sfTexture *texture_background_game;
    sfSprite *sprite_background_game;
    sfTexture *texture_pause_game;
    sfSprite *sprite_pause_game;
    sfVector2f position_pause;
    sfView *view;
    sfView *fight_view;
} background_t;

typedef struct inventory
{
    int state;
    sfText *pv_text;
    sfText *pv_str;
    sfFont *font;
    sfTexture *text_menu;
    sfVector2f pos_menu;
    sfSprite *menu;
    int progress;
    sfText *progr_text;
    sfText *progr_str;
    elem_t *progr;
    sfIntRect box_progr;

    elem_t *pistol;
    elem_t *medic;
    elem_t *grenade;
    elem_t *throw_knife;
    elem_t *back;
    int pistol_nb;
    int medic_nb;
    int grenade_nb;
    int throw_knife_nb;
    sfSound *pistol_sound;
    sfSound *medic_sound;
    sfSound *throw_sound;
    sfSound *grenade_sound;
    sfSoundBuffer *pistol_buffer;
    sfSoundBuffer *medic_buffer;
    sfSoundBuffer *throw_buffer;
    sfSoundBuffer *grenade_buffer;
} inventory_t;

typedef struct combat
{
    int check;
    int pv;
    int pv_e;
    int inventory;
    int turn;
    int z_stunned;
    sfTexture *text_background;
    sfSprite *background;
    sfClock *clock;
    sfTime time;
    sfSound *axe;
    sfSound *attack;
    sfSound *search;
    sfSoundBuffer *axe_buff;
    sfSoundBuffer *attack_buff;
    sfSoundBuffer *search_buff;
    sfMusic *music;

    elem_t *enemy_pv;
    elem_t *player_pv;
    elem_t *player;
    elem_t *enemy;
    elem_t *cut;
    elem_t *bag;
    elem_t *flee;
    elem_t *pause;
    sfIntRect box_player;
    sfIntRect box_enemy;
    sfIntRect box_player_pv;
    sfIntRect box_enemy_pv;
} combat_t;

typedef struct
{
    sfTexture *texture_character;
    sfSprite *sprite_character;
    sfIntRect rect_character;
    sfVector2f position_character;
    sfClock *clock;
    sfClock *move_clock;
    sfInt64 time;
    sfInt64 move_time;
    int move;
    char **map;
    int x;
    int y;
} character_t;

typedef struct
{
    sfTexture *texture_rain;
    sfSprite *sprite_rain;
    sfVector2f rain_position;
    sfTexture *texture_fire;
    sfSprite *sprite_fire;
    sfIntRect rect_fire;
    sfVector2f position_fire;
    sfClock *rain_clock;
    sfInt64 rain_time;
} effects_t;

typedef struct pnj_interaction
{
    sfTexture *texture_pnj;
    sfTexture *texture_pnj2;
    sfTexture *texture_pnj3;
    sfSprite *sprite_pnj;
    sfSprite *sprite_pnj2;
    sfSprite *sprite_pnj3;
    sfVector2f position_pnj;
    sfVector2f position_pnj2;
    sfVector2f position_pnj3;
    sfVector2f position_actual_character;
    int pnj_actual; //PNJ who speak
} pnj_interaction_t;

typedef struct dialog_pnj
{
    sfTexture *texture_pnj1_dialog1;
    sfTexture *texture_pnj1_dialog2;
    sfTexture *texture_pnj2_dialog1;
    sfTexture *texture_pnj3_dialog1;
    sfTexture *texture_pnj3_dialog2;
    sfTexture *texture_pnj3_dialog3;
    sfSprite *sprite_pnj1_dialog1;
    sfSprite *sprite_pnj1_dialog2;
    sfSprite *sprite_pnj2_dialog1;
    sfSprite *sprite_pnj3_dialog1;
    sfSprite *sprite_pnj3_dialog2;
    sfSprite *sprite_pnj3_dialog3;
    sfVector2f position_pnj_dialog;
    int dialog_actual; // NUMBER = PART OF DIALOGUE
    int dialog_statut; // 1 = ACTIVE ; 0 = DESACTIVATE
    int choice; //1 = YES ; 2 = NO
} dialog_pnj_t;

typedef struct quests
{
    sfTexture *texture_quest1;
    sfSprite *sprite_quest1;
    sfVector2f position_quests;
    sfTexture *texture_success;
    sfSprite *sprite_success;
    int success; // 0 = NO ACTIVATE ; 1 = QUEST SUCCESS
    int quest1; // 0 = NO BEGIN ; 1 = IN PROGRESS ; 2 = FINISH
    int quests_status; // There is a quest in progress
} quests_t;


typedef struct
{
    window_t *manage_window;
    start_t *start;
    background_t *background;
    combat_t *combat;
    inventory_t *inventory;
    character_t *character;
    pnj_interaction_t *pnj;
    dialog_pnj_t *dialog;
    quests_t *quests;
    effects_t *effects;
} hub_t;

#endif