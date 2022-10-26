#include <stdio.h>

typedef struct {
const char *description;
float value;
} swag;

typedef struct {
swag *swag;
const char *sequence;
} combination;

typedef struct {
combination numbers;
const char *make;
} safe;


// s.numbers.swag->description;

int main()
{
// The bank created its safe like this:
swag gold = {"GOLD!", 1000000.0};
combination numbers = {&gold, "6502"};

safe s = {numbers, "RAMACON250"};

printf("Contents = %s\n", s.numbers.swag->description);

return 0;
}