/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_htp.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void htp_ini(start_t *start)
{
    sfVector2f pos;

    start->htp->texture = sfTexture_createFromFile(\
    "asset/texture/button/htp.png", NULL);
    start->htp->sprite = sfSprite_create();
    sfSprite_setTexture(start->htp->sprite, start->htp->texture, sfTrue);
    start->htp->pos.x = 1600;
    start->htp->pos.y = 0;
    sfSprite_setPosition(start->htp->sprite, start->htp->pos);
    start->htp_text = sfText_create();
    set_text(start->htp_text);
    pos.x = 20;
    pos.y = 150;
    sfText_setPosition(start->htp_text, pos);
    sfText_setCharacterSize(start->htp_text, 30);
    sfText_setColor(start->htp_text, sfWhite);
    start->font = sfFont_createFromFile("asset/police/arial.ttf");
    sfText_setFont(start->htp_text, start->font);
}

void set_text(sfText *text)
{
    sfText_setString(text, "General: In this adventure your goal is to survive\
and reach the exit of the town. You can restart the game using the start\
button in pause menu \navailable by [Escape] or resume it by the arrow\
button and even left it with the exit button.\nYour inventory is displayed\
on the top left of the screen.\nYou start with 100 PV it symbolizes your \
health that you will loose by beeing hit. At the right a line that depicts\
your progression in the story.\n\nOn the map: You can move using:\
\n\t[Z]: forward [Q]: left [S]: backward [D]: right and interact with NPCs: [T]\
, [ENTER] to follow dialogs.\nYou can use a medikit in your inventory that\
will give you 40PVs. The other items are not usable on the map.\n\nCombat\
: In combat your health and the enemy's one are symbolized by the red\
dashes on the bottom that disapear through the combat. When you \nchoose an\
action the enemy will strike back, this will take you 10PVs. You can\
choose three actions in combat:\nCut: Does 20PVs of damage on the enemy.\
\nFlee: Escapes the combat but you'll loose 20PVs.\nBag: Displays your \
inventory where you can use four items including the medikit that we\
described earlier and three others:\n\tGrenade: Kill the enemy in one hit.\
\n\tPistol: Each shot does 30PVs damage to the enemy.\n\tThrowing knife: Does\
10PVs damage to the enemy but stuns him for the next two rounds and allows\
you to flee without beeing hit.\n\nAfter a combat you get a random item.");
}