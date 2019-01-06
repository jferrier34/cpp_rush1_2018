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
	return (n);
}

void 		delete(Object *class)
{
	if (!class)
		raise("You otha brotha can't deny\n");
	else{
		((Class *)class)->__dtor__(class);
		free(class);
	}
}
