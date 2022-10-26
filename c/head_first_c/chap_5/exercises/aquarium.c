#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct exercise {
const char *description;
float duration;
};

struct meal {
const char *ingredients;
float weight;
};

struct preferences {
struct meal food;
struct exercise exercise;
};

struct fish {
const char *name;
const char *species;
int teeth;
int age;

struct preferences care;
};

void label(struct fish f)
{
// printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n", f.name, f.species, f.teeth, f.age);
printf("\n Name: %s\n Species: %s\n Food ingredients: %s\n Food weight: %2.2f lbs\n Exercise description: %s\n Exercise duration: %2.2f hours\n", f.name, f.species, f.care.food.ingredients, f.care.food.weight, f.care.exercise.description, f.care.exercise.duration);
}

int main()
{
struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};

label(snappy);

return 0;
}

