/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** core game function
*/
#include "../include/my.h"
#include "../include/struct.h"
#include "../include/csfml.h"

void map_read(hub_t *hub)
{
    FILE *fd;
    char *line = NULL;
    size_t len = 0;
    hub->character->map = NULL;
    hub->character->x = 15;
    hub->character->y = 15;

    fd = fopen("map1.txt", "r");
    if (fd == NULL)
        write(2, "Error, open map1.txt\n", 22);
    hub->character->map = malloc(sizeof(char *) * 35);
    for (int y = 0;(getline(&line, &len, fd)) != -1; y++) {
        hub->character->map[y] = malloc(sizeof(char) * 61);
        for (int x = 0; x < 61; x++)
            hub->character->map[y][x] = line[x];
    }
    free(line);
}