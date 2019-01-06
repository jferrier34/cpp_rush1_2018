/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class   base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    delete(this);
}

static Object *miltipli(Object *this, Object *other)
{
    CharClass *ret = new(Char, ((CharClass *)this)->c *
     ((CharClass *)other)->c);
    return (ret);
}

static Object *addi(Object *this, Object *other)
{
    CharClass *ret = new(Char, ((CharClass *)this)->c +
     ((CharClass *)other)->c);
    return (ret);
}

static Object *sousi(Object *this, Object *other)
{
    CharClass *ret = new(Char, ((CharClass *)this)->c -
     ((CharClass *)other)->c);
    return (ret);
}

static Object *divisio(Object *this, Object *other)
{
    if (((CharClass *)other)->c == 0)
    {
        CharClass *ret = new(Char, 0);
        return (ret);
    }
    CharClass *ret = new(Char, ((CharClass *)this)->c /
     ((CharClass *)other)->c);
    return (ret);
}

static bool gte(Object *this, Object *other)
{
    if (((CharClass *)this)->c > ((CharClass *)other)->c)
        return (true);
    return (false);
}

static bool lte(Object *this, Object *other)
{
    if (((CharClass *)this)->c < ((CharClass *)other)->c)
        return (true);
    return (false);
}

static bool eqe(Object *this, Object *other)
{
    if (((CharClass *)this)->c == ((CharClass *)other)->c)
        return (true);
    return (false);
}

static char const *Printer(CharClass *this)
{
    char *str = malloc(40);
    sprintf(str, "<Char (%c)>", this->c);
    return (str);
}

static CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
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

Class   *Char = (Class *)&_description;