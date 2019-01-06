/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float c;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->c = va_arg(*args, float);
}

static void Float_dtor(FloatClass *this)
{
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

static Object *gte(Object *this, Object *other)
{
    if (((FloatClass *)this)->c > ((FloatClass *)other)->c)
        return (this);
    return (NULL);
}

static Object *lte(Object *this, Object *other)
{
    if (((FloatClass *)this)->c < ((FloatClass *)other)->c)
        return (this);
    return (NULL);
}

static Object *eqe(Object *this, Object *other)
{
    if (((FloatClass *)this)->c == ((FloatClass *)other)->c)
        return (this);
    return (NULL);
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
        .__eq__ = (binary_operator_t)&eqe,
        .__gt__ = (binary_operator_t)&gte,
        .__lt__ = (binary_operator_t)&lte
    },
    .c = 0
};

Class   *Float = (Class *)&_description;