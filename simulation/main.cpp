#include "Galaxy.h"
#include "Star.h"
#include "Calculator.h"

int main() {
    std::string galaxyFile = "../data/hygdata_cleaned.csv";
    Galaxy galaxy;
    galaxy.load(galaxyFile);


    return 0;
}