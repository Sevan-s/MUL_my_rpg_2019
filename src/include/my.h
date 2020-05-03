/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** libmy
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include "struct.h"
#include "csfml.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
int my_getnbr(char const *str);
char *nbr_in_str(int nbr);

//game_loop
void game_loop(void);

//initialization_function
void structuring_malloc(hub_t *hub);
void structuring_sec(hub_t *hub);
void initialization(hub_t *hub);
void initialize_sec(hub_t *hub);
void display_parameter(window_t *manage_window);
void start_sprite(start_t *start);
void start_position(start_t *start);
void pause_sprite(start_t *start);
void pause_position(start_t *start);
void htp_ini(start_t *start);
void set_text(sfText *text);
void background_game_ini(hub_t *hub);
void initialization_character(character_t *character);
void map_read(hub_t *hub);

//inventory
void inventory_ini(inventory_t *inventory, character_t *character);
void ini_pv(inventory_t *inventory, sfVector2f character);
void inventory_display(window_t *window_s, inventory_t *inventory, hub_t *hub);
void display_pv(window_t *window_s, inventory_t *inventory, hub_t *hub);
void reward(inventory_t *inventory);

//resize_inventory
void resize_inventory(inventory_t *inventory, sfVector2f character, \
window_t *window_s);
void replace_inv_map(inventory_t *inventory, window_t *window_s, \
sfVector2f character);
void resize_inv_map(inventory_t *inventory);

//ini_items
void init_grenade(inventory_t *inventory, sfVector2f character);
void init_pistol(inventory_t *inventory, sfVector2f character);
void init_medic(inventory_t *inventory, sfVector2f character);
void init_throw(inventory_t *inventory, sfVector2f character);
void back_ini(inventory_t *inventory, sfVector2f character);

// ini effects
void effects_game_ini(effects_t *effects);

//progr
void ini_progr(inventory_t *inventory, sfVector2f character);
void ini_progr_score(inventory_t *inventory, sfVector2f character);
void display_progr(window_t *window_s, inventory_t *inventory, \
sfVector2f character);
void resize_progr(inventory_t *inventory, sfVector2f character);
void destroy_progr(inventory_t *inventory);

//inventory_event
void inventory_event(inventory_t *inventory, hub_t *hub, \
sfMouseButtonEvent event);
void detect_medic(inventory_t *inventory, hub_t *hub, \
sfMouseButtonEvent event);
void grenade(inventory_t *inventory, hub_t *hub);
void pistol(inventory_t *inventory, hub_t *hub);
void medic(inventory_t *inventory, hub_t *hub);
void throw_knife(inventory_t *inventory, hub_t *hub);

//combat_ini
void combat_ini(combat_t *combat, window_t *window_s);
void combat_ini_pv_p(combat_t *combat);
void combat_ini_pv_e(combat_t *combat);
void combat_ini_player(combat_t *combat);
void combat_ini_enemy(combat_t *combat);

//combat_ini_sec
void combat_ini_scene(combat_t *combat);
void combat_ini_cut(combat_t *combat);
void combat_ini_bag(combat_t *combat);
void combat_ini_flee(combat_t *combat);
void combat_ini_pause(combat_t *combat);

//analyse_events_function
int analyse_events(hub_t *hub);
int switch_event(hub_t *hub, int *result);
int button_click_detection(hub_t *hub);
int manage_mouse_click(sfMouseButtonEvent event, window_t *manage_window, \
start_t *start);
void manage_escape(hub_t *hub);
int manage_pause_menu_click(sfMouseButtonEvent event, \
window_t *manage_window, start_t *start, hub_t *hub);
void manage_pause_Escape(window_t *manage_window, start_t *start, hub_t *hub);
void manage_pause_click(sfMouseButtonEvent event, window_t *manage_window, \
start_t *start, hub_t *hub);
void move_character(hub_t *hub);

//menu_function
void menu(hub_t *hub, int *result);
void menu_start(start_t *start, window_t *manage_window);
void menu_pause(start_t *start, window_t *manage_window);

//display_function
void game_display(hub_t *hub);

//move_character
void move_character(hub_t *hub);
void move_character_next(hub_t *hub);

//combat_scene
int combat_scene(combat_t *combat, window_t *window_s, hub_t *hub);
void display_combat(hub_t *hub, combat_t *combat, window_t *window_s);
void idle(combat_t *combat);
void animate(combat_t *combat, window_t *window_s);
int check_life(combat_t *combat);

//resize_combat
void resize_combat(inventory_t *inventory);
void replace_combat(inventory_t *inventory);

//combat_core
void core(hub_t *hub, int *result, int *outcome, sfClock *z_move);
void display_condition(hub_t *hub);

//zombie_attack
void zombie_attack(window_t *window_s, combat_t *combat);

//combat_evnt_anlys
void combat_buttons(hub_t *hub);
void cut_click(window_t *window_s, sfMouseButtonEvent event, \
combat_t *combat, hub_t *hub);
void combat_pause_click(sfEvent event, window_t *manage_window, \
start_t *start);
void flee_click(window_t *window_s, sfMouseButtonEvent event, combat_t *combat);
void bag_click(sfMouseButtonEvent event, \
inventory_t *inventory, combat_t *combat);
void display_fight_view(hub_t *hub);

//cut
void cut(hub_t *hub, window_t *window_s, combat_t *combat);
void init_cut(combat_t *combat);
void check_first(hub_t *hub, float sec, window_t *window_s, combat_t *combat);
void check_sec(hub_t *hub, float sec, window_t *window_s, combat_t *combat);
void sliced(window_t *window_s, combat_t *combat);

//result
int result_cmb(int outcome, int result, window_t *window_s, hub_t *hub);

//destroy_inventory
void destroy_inventory(inventory_t *inventory);

//destroy_combat
void destroy_combat(combat_t *combat);
void destroy_combat_sec(combat_t *combat);

//destroy_function
void destroy_all(hub_t *hub);
void destroy_start(start_t *start);
void destroy_start_sec(start_t *start);
void destroy_background(background_t *background);
void destroy_window(window_t *manage_window);
void destroy_combat(combat_t *combat);

//move_character
void move_character(hub_t *hub);
int move_character_left(hub_t *hub);
int move_character_right(hub_t *hub);
int move_character_down(hub_t *hub);
int move_character_up(hub_t *hub);
void display_view(hub_t *hub);
void set_pnj_clock(character_t *character);

//parrallax
void init_parrallax(hub_t *hub);
void pause_button_position(hub_t *hub);
void clock_parralax(hub_t *hub);

//init_PNJ
void init_PNJ(hub_t *hub);

//Detection PNJ
void detect_pnj(hub_t *hub);
void detect_pnj_sec(hub_t *hub);

//display_dialog
void display_dialog(hub_t *hub, sfSprite *dialog);
void pnj_dialog(hub_t *hub);
void pnj_dialog_sec(hub_t *hub);
void quest_validation(hub_t *hub);

//init_dialog
void texture_dialog(hub_t *hub);
void position_sprite_dialog(hub_t *hub);

//init_quests
void init_quests(hub_t *hub);

//display_quests
void display_quest(hub_t *hub);
void position_sprites_quests(hub_t *hub);
#endif /* !LIBMY_H_ */
