#include "additional_stuff.h"


int getValueFromDiapasone(int a, int b)
{
    srand(time_t(nullptr));
    return a + rand() % (b - a + 1);
}

bool FlipDice(double probability)
{
    probability *= 1000;
    int result = getValueFromDiapasone(0, 1000);

    return result < (probability - 1);
}
