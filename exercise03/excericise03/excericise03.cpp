
#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

int getRandom() {
    // Konstanter för min och max till slumptals distribution
    const int MIN = 1;
    const int MAX = 10;

    // Skapa en slumptals generator
    random_device dev;
    mt19937 rng(dev());
    
    // Skapa en slumptals distribution
    uniform_int_distribution<mt19937::result_type> dist(MIN, MAX); 

    // Här hämtar jag ett slumptal
    return dist(rng);  // Varje anrop till dist(rng) ger nytt slumptal
    
}

void random_loop_function() {
    int slump = getRandom();
    cout << "random-loop: ";
    for (int i=1; i<=slump; i++) {
        cout << i << " ";
    }
    cout << "\n";
}


void multiplication() {
    cout << "Hilda, what number do you want a multiplication table for? ";
    int number;
    cin >> number;

    cout << "Multiplikationstabell för " << number << "\n";
    cout << "===================================\n";
    for (int i=1; i<=10; i++) {
        cout << i << "\t*\t" << number << "\t=\t" << (i*number) << "\n";
    }
}

bool isPrime(int talet) {

    for (int i=2; i < talet; i++) {
        if (!(talet % i)) {     // talet % i -> 0 == false, else true
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Deluppgift 1 - for-loop

    cout << "for-loop: ";
    for (int loopCnt = 1; loopCnt <= 10; loopCnt++ ) {
        cout << loopCnt << " ";
    }
    cout << "\n";

    // Deluppgift 2 - while-loop
    cout << "while-loop: ";
    int loopCounter = 1;
    while (loopCounter <= 10) {
        cout << loopCounter << " ";
        loopCounter++;
    }
    cout << "\n";

    // Deluppgift 3 - do-while-loop
    loopCounter = 1;
    cout << "do-while: ";
    do {
        cout << loopCounter << " ";
        loopCounter++;
    } while (loopCounter <= 10);
    cout << "\n";

    // Deluppgift 4 - random-loop
    random_loop_function();

    // Deluppgift 5 - multiplication
    //multiplication();

    // Deluppgift 6 - primtal
    cout << "Mata in ett tal: ";
    int tal;
    cin >> tal;
    if (isPrime(tal)) {
        cout << tal << " är ett primtal!\n";
    } else {
        cout << tal << " är inte ett primtal!\n";
    }

    /*
     *  4: ej prim
     *  87: ej prim
     *  139: är prim
     *  567: ej prim
     *  991: är prim
     *  999: ej prim
    */
    return 0;
}
