/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
}

static Object *additio(Object *this, Object *other)
{
    PointClass *ret = new(Point, ((PointClass *)this)->x +
    ((PointClass *)other)->x, ((PointClass *)this)->y +
    ((PointClass *)other)->y);
    return (ret);
}

static Object *substractio(Object *this, Object *other)
{
    PointClass *ret = new(Point, ((PointClass *)this)->x -
    ((PointClass *)other)->x, ((PointClass *)this)->y -
    ((PointClass *)other)->y);
    return (ret);
}

static char const *Printer(PointClass *this)
{
    char *str = malloc(40);
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return (str);
}

static PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Printer,
        .__add__ = (binary_operator_t)&additio,
        .__sub__ = (binary_operator_t)&substractio,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

Class   *Point = (Class *)&_description;
