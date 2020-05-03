/*
** EPITECH PROJECT, 2020
** PNJ_dialog
** File description:
** PNJ_dialog
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void display_dialog(hub_t *hub, sfSprite *dialog)
{
    sfRenderWindow_drawSprite(hub->manage_window->window, dialog, NULL);
}

void pnj_dialog(hub_t *hub)
{
    if (hub->pnj->pnj_actual == 1) {
        switch (hub->dialog->dialog_actual) {
        case 1:
            quest_validation(hub);
            display_dialog(hub, hub->dialog->sprite_pnj1_dialog1);
            break;
        case 2:
            display_dialog(hub, hub->dialog->sprite_pnj1_dialog2);
            break;
        default:
            if (hub->quests->success == 1) {
                hub->quests->success = 0;
            }
            hub->dialog->dialog_statut = 0;
            hub->dialog->dialog_actual = 0;
            break;
        }
    }
    pnj_dialog_sec(hub);
}

void pnj_dialog_sec(hub_t *hub)
{
    if (hub->pnj->pnj_actual == 2) {
        switch (hub->dialog->dialog_actual) {
        case 1:
            quest_validation(hub);
            display_dialog(hub, hub->dialog->sprite_pnj2_dialog1);
            break;
        default:
            if (hub->quests->success == 1) {
                hub->quests->success = 0;
            }
            hub->manage_window->scene = 3;
            hub->dialog->dialog_statut = 0;
            hub->dialog->dialog_actual = 0;
            break;
        }
    }
}

void quest_validation(hub_t *hub)
{
    if (hub->quests->quest1 == 1) {
        hub->quests->quest1 = 2;
        hub->quests->success = 1;
        hub->inventory->progress += 25;
    }
}