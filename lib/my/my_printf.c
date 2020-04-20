/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_printf Fonction
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int flag(va_list ap, const char *format, int count)
{
    switch (format[count]) {
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char*));
            break;
        default:
            return (84);
            break;
    }
}

int my_printf(const char *format, ...)
{
    int count = 0;
    int j = my_strlen(format);

    va_list ap;
    va_start(ap, format);
    while (count < j) {
        if (format[count] == '%') {
            count++;
            flag(ap, format, count);
        }
        else if (format[count] != '%') {
            my_putchar(format[count]);
        }
        count++;
    }
    va_end(ap);
    return (0);
}