/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class   base;
    int c;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
}

static Object *addi(Object *this, Object *other)
{
    IntClass *ret = new(Int, ((IntClass *)this)->c +
     ((IntClass *)other)->c);
    return (ret);
}

static Object *sousi(Object *this, Object *other)
{
    IntClass *ret = new(Int, ((IntClass *)this)->c -
     ((IntClass *)other)->c);
    return (ret);
}

static Object *miltipli(Object *this, Object *other)
{
    IntClass *ret = new(Int, ((IntClass *)this)->c *
     ((IntClass *)other)->c);
    return (ret);
}

static Object *divisio(Object *this, Object *other)
{
    if (((IntClass *)other)->c == 0)
    {
        IntClass *ret = new(Int, 0);
        return (ret);
    }
    IntClass *ret = new(Int, ((IntClass *)this)->c /
     ((IntClass *)other)->c);
    return (ret);
}

static bool gte(Object *this, Object *other)
{
    if (((IntClass *)this)->c > ((IntClass *)other)->c)
        return (true);
    return (false);
}

static bool lte(Object *this, Object *other)
{
    if (((IntClass *)this)->c < ((IntClass *)other)->c)
        return (true);
    return (false);
}

static bool eqe(Object *this, Object *other)
{
    if (((IntClass *)this)->c == ((IntClass *)other)->c)
        return (true);
    return (false);
}

static char const *Printer(IntClass *this)
{
    char *str = malloc(40);
    sprintf(str, "<Int (%f)>", this->c);
    return (str);
}

static IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Printer,
        .__add__ = (binary_operator_t)&addi,
        .__sub__ = (binary_operator_t)&sousi,
        .__mul__ = (binary_operator_t)&miltipli,
        .__div__ = (binary_operator_t)&divisio,
        .__eq__ = (binary_comparator_t)&eqe,
        .__gt__ = (binary_comparator_t)&gte,
        .__lt__ = (binary_comparator_t)&lte
    },
    .c = 0
};

Class   *Int = (Class *)&_description;