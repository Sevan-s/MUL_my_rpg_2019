/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** function
*/

#include "my.h"

int my_strlen(const char *str);

int my_getnbr(char const *str)
{
    int nbr = 0;
    int size = my_strlen(str);
    int force = 1;

    for (int i = (size - 1); i >= 0; i--) {
        if (str[i] != '\n') {
            nbr += (str[i] - 48) * force;
            force *= 10;
        }
    }
    return (nbr);
}