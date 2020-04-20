/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main function
*/

#include "include/my.h"

void description(void)
{
    my_printf("./my_rpg\n");
    my_printf("USAGE\n");
    my_printf("  \n");
    my_printf("\nUSER INTERACTIONS\n");
    my_printf("the different display buttons\n");
    my_printf("  Escape:   pause game\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        description();
        return (0);
    }
    game_loop();
    return (0);
}