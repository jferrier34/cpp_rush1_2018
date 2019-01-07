/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/

#ifndef RAISE_H
#define RAISE_H

#include <stdio.h>
#include <stdlib.h>

#define raise(msg)                                              \
do {                                                            \
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);   \
   	exit(0);                                                    \
} while (0)

#endif

