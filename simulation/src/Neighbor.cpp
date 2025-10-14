#include "../include/Neighbor.h"
#include "../include/Calculator.h"

Neighbor::Neighbor(Node *target, Node *node) {
    this->target = target;
    this->node = node;
    distance = Calculator::calcDistance(target, node);
}
