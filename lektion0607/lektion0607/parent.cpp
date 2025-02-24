#include "parent.h"

#include <iostream>

using namespace std;

parent::parent(int x) {
    this->x = x;
    this->z = 2 * x;
    cout << "This is the constructor of the parent\n";
}

void parent::my_method() {
    x++;
    z = 2*x;
    cout << "This is the my_method() of the parent\n";
}


