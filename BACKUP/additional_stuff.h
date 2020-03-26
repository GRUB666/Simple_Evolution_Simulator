#ifndef ADDITIONAL_STUFF_H
#define ADDITIONAL_STUFF_H

#include <ctime>
#include <random>
#include <cmath>

#include "object.h"


int getValueFromDiapasone(int a, int b);

bool FlipDice(double probability);

double getDistance(Object &obj1, Object &obj2);

double getAngleBetweenObjects(Object &obj1, Object &obj2);

#endif // ADDITIONAL_STUFF_H
