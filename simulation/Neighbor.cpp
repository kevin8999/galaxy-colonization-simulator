#include "Neighbor.h"
#include "Calculator.h"

float Neighbor::calcDistance() {
    distance = Calculator::calcDistance(target, node);
    return distance;
}
