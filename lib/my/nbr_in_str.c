/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** function
*/
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *nbr_in_str(int nbr)
{
    char *str = NULL;
    int save = nbr;
    int count = 0;
    int i = 0;

    for (; save >= 1; count++)
        save /= 10;
    str = malloc(sizeof(char) * count);
    i = count;
    str[i] = '\0';
    i--;
    for (; i >= 0; i--) {
        str[i] = (nbr % 10) + 48;
        nbr /= 10;
    }
    return (str);
}