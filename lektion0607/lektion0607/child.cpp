#include "child.h"

#include <iostream>

using namespace std;

child::child(int x, int y):parent(x) {
    this->y = y;
    cout << "This is the constructor of the child class\n";
}

void child::my_method() {
    parent::my_method();
    y++;
    cout << "This is the my_method() of the child\n";
}
