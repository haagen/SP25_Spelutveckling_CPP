#include "dice.h"
#include <random>

dice::dice(int min, int max) {
    this->min = min;
    this->max = max;
    srand(time(nullptr));
}

int dice::roll() {
    int diff = max - min + 1;
    return min + (rand() % diff);
}