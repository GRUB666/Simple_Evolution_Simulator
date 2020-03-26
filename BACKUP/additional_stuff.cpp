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

double getDistance(Object &obj1, Object &obj2)
{
    return sqrt(pow(obj2.getXPos() - obj1.getXPos(), 2) + pow(obj2.getYPos() - obj1.getYPos(), 2));
}

double getAngleBetweenObjects(Object &obj1, Object &obj2)
{
    return atan2(obj2.getXPos() - obj1.getXPos(), obj2.getYPos() - obj1.getYPos());
}
