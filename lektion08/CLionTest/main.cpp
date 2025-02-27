
#include "dice.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    dice d6(1, 6);

    cout << "Random: ";
    for (int i=0; i<10; i++) {
        cout << d6.roll() << " ";
    }
    cout << "\n";
    
    return 0;
}
