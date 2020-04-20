/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_putnbr_base function
*/

#include <unistd.h>
void my_putchar(char c);
int my_strlen(const char *str);

int my_putnbr_base(int nbr, char const *base)
{
    int save = 0;
    int str_size = 0;

    if (nbr < 0) {
        write(1, "Error, not a positive number", 28);
        return (84);
    }
    str_size = my_strlen(base);
    save = nbr % str_size;
    nbr = nbr / str_size;
    if (nbr > 0) {
        my_putnbr_base(nbr, base);
    }
    my_putchar(base[save]);
    return (nbr);
}