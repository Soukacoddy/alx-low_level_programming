#ifndef _DOG_H
#define _DOG_H
#include <stdio.h>
#include <stdlib.h>

typedef struct dog dog;

/**
 * struct dog - check the code
 * @name: pram
 * @age: pram
 * @owner: pram
 *
 * Description: dog struct
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void init_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
