#include "new.h"
#include "player.h"
#include <string.h>

Object 		*new(Class *class, ...)
{
	va_list va;
	if (!class){
		raise("I like big butts\n");
		return (NULL);
	}
	Object *n = malloc(class->__size__);
	if (!n){
		raise("And I cannot lie\n");
		return (NULL);
	}
	va_start(va, NULL);
	n = memcpy(n, class, class->__size__);
	((Class *)n)->__ctor__(n, &va);
	va_end(va);
	return (n);
}

Object 		*va_new(Class *class, va_list *ap)
{
	if (!class){
		raise("I like big butts\n");
		return (NULL);
	}
	Object *n = malloc(class->__size__);
	if (!n){
		raise("And I cannot lie\n");
		return (NULL);
	}
	n = memcpy(n, class, class->__size__);
	((Class *)n)->__ctor__(n, ap);
	va_end(*ap);
	return (n);	
}

void 		delete(Object *class)
{
	if (!class){
		raise("You otha brotha can't deny\n");
		return ;
	}
	else{
		((Class *)class)->__dtor__(class);
		free(class);
	}
}
