#include "Star.h"
#include "Node.h"

class Calculator {
    // Performs calculations on the Galaxy and Star classes

public:
    // Calculates distance between star 1 and star 2
    static double calcDistance(Star& s1, Star& s2);
    static double calcDistance(Star *s1, Star *s2);
    static double calcDistance(Node* n1, Node* n2);
};