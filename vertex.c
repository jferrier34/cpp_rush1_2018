/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
}

static Object *additio(Object *this, Object *other)
{
    VertexClass *ret = new(Vertex, ((VertexClass *)this)->x +
     ((VertexClass *)other)->x, ((VertexClass *)this)->y +
      ((VertexClass *)other)->y, ((VertexClass *)this)->z +
      ((VertexClass *)other)->z);
    return (ret);
}

static Object *substractio(Object *this, Object *other)
{
    VertexClass *ret = new(Vertex, ((VertexClass *)this)->x -
     ((VertexClass *)other)->x, ((VertexClass *)this)->y -
      ((VertexClass *)other)->y, ((VertexClass *)this)->z -
      ((VertexClass *)other)->z);
    return (ret);
}

static char const *Printer(VertexClass *this)
{
    char *str = malloc(40);
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
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

Class   *Vertex = (Class *)&_description;