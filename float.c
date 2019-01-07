/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class   base;
    float c;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->c = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    this->c = 0;
}

static Object *addi(Object *this, Object *other)
{
    FloatClass *ret = new(Float, ((FloatClass *)this)->c +
     ((FloatClass *)other)->c);
    return (ret);
}

static Object *sousi(Object *this, Object *other)
{
    FloatClass *ret = new(Float, ((FloatClass *)this)->c -
     ((FloatClass *)other)->c);
    return (ret);
}

static Object *miltipli(Object *this, Object *other)
{
    FloatClass *ret = new(Float, ((FloatClass *)this)->c *
     ((FloatClass *)other)->c);
    return (ret);
}

static Object *divisio(Object *this, Object *other)
{
    if (((FloatClass *)other)->c == 0)
    {
        FloatClass *ret = new(Float, 0);
        return (ret);
    }
    FloatClass *ret = new(Float, ((FloatClass *)this)->c /
     ((FloatClass *)other)->c);
    return (ret);
}

static bool gte(Object *this, Object *other)
{
    if (((FloatClass *)this)->c > ((FloatClass *)other)->c)
        return (true);
    return (false);
}

static bool lte(Object *this, Object *other)
{
    if (((FloatClass *)this)->c < ((FloatClass *)other)->c)
        return (true);
    return (false);
}

static bool eqe(Object *this, Object *other)
{
    if (((FloatClass *)this)->c == ((FloatClass *)other)->c)
        return (true);
    return (false);
}


static char const *Printer(FloatClass *this)
{
    char *str = malloc(40);
    sprintf(str, "<Float (%f)>", this->c);
    return (str);
}

static FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
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

Class   *Float = (Class *)&_description;