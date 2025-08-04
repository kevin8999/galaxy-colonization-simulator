#include "Galaxy.h"
#include <thread>

int main() {
    std::string dataFile = "../data/hygdata_cleaned.csv";
    Galaxy galaxy;
    galaxy.load(dataFile);

    galaxy.start();

    // Create threads
    std::thread colonization(&Galaxy::run, &galaxy);
    std::thread userInput(&Galaxy::timerControl, &galaxy);

    // Wait for each thread to finish
    colonization.join();
    userInput.join();

    return 0;
}