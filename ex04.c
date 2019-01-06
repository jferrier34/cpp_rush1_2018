/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** ex04.c
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "char.h"
#include "vertex.h"

int         main(void)
{
    Object  *p1 = new(Char, 'x');
    Object  *p2 = new(Char, 'd');

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));

    return (0);
}