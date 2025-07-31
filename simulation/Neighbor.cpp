#include "Neighbor.h"
#include "Calculator.h"

Neighbor::Neighbor(Node *target, Node *node) {
    this->target = target;
    this->node = node;
    distance = Calculator::calcDistance(target, node);
}
