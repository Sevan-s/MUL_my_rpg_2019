/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_put_nbr function
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nbr)
{
    if (nbr <= -2147483648 || nbr >= 2147483648) {
        write(1, "excessive number for int", 24);
        return (0);
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
    else
        my_putchar(nbr + '0');
    return (0);
}