/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_strlen function
*/

int my_strlen(const char *str)
{
    int count;
    for (count = 0; str[count] != 0; count++);
    return (count);
}