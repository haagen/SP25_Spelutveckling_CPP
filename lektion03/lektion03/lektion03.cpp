
#include <iostream>
#include "lektion03.h"

using namespace std;

int max(int tal1, int tal2) {
    if (tal1 > tal2) {
        return tal1;
    }
    return tal2;
}

int main(int argc, char* argv[])
{
    // ----------------------------------------------------
    // FOR
    // ----------------------------------------------------

    /*
            for(
                init - körs en gång, innan loopen startar
                condition - kontrollerar om loopen skall starta
                            om sant - starta loopen
                counter - anropas när loopen är klar (efter varje
                            loop).
            )
     */
    cout << "This is a for-loop!\n";
    for (int i=0; i < 5; i++) {
        cout << i << "\n";
    }

    cout << "Calculate the sum of all integers between 0 and 42: ";
    int sum=0;
    for (int i=0; i <= 42; i++) {
        sum += i;
    }
    cout << sum << "\n";

    cout << "A reversed loop - 4 -> 0\n";
    for (int i=4; i>=0; i--) {
        cout << i << "\n";
    }

    // ----------------------------------------------------
    // WHILE
    // ----------------------------------------------------    

    /*
        while (
            condition - starta loopen så länge detta är sant
        )
    */

    cout << "This is a while-loop\n";
    int counter = 0;
    while (counter < 5) {
        cout << counter << " ";
        counter++;
    }
    cout << "\n";

    cout << "While-loop 2: \n";
    while (true) {
        cout << counter << " ";
        counter--;
        if (counter < 0) {
            break;
        }
    }
    cout << "\n";

    cout << "While-loop number 3: ";
    counter = 0;
    while (counter <= 30) {
        if (counter % 3 == 0) {
            cout << counter << " ";
        }
        counter++;
    }
    cout << "\n";

    // ----------------------------------------------------
    // DO-WHILE
    // ----------------------------------------------------    

    /*
        do {
        
        } while (
            condition - starta loopen så länge detta är sant
        )
    */

    cout << "do-while loop. \n";
    sum = 0;
    do {
        int number;
        cout << "Enter a (positive) number: ";
        cin >> number;
        if (number < 0) {
            cout << "Not allowed\n";
            continue;
        }
        sum += number;
    } while (sum < 100);
    cout << "The sum: " << sum << "\n";

    // ----------------------------------------------------
    // FUNKTIONER
    // ---------------------------------------------------- 

    /*
        max(43, 8)
        43 och 8 är argument
        resultaten bör bli 43
    */
    cout << "The max of 43 and 8: " << max(43, 8) << "\n";
    int tal = 42;
    int maxTal = max(43, tal);
    sum = add(43, 8);
    //cout << "The sum of 43 and 8: " << sum << "\n";
    println("The sum of 43 and 8: " + to_string(sum) );

    // ----------------------------------------------------
    // Ett större exempel
    // ----------------------------------------------------

    sum = 0;
    int value;
    do {
        cout << "Enter a value (0 or less to stop) > ";
        cin >> value;

        if (value > 0) {
            sum = add(sum, value);
        }
    } while (value > 0);
    println("The sum of your numbers are: " + to_string(sum));

    
    return 0;
}

int add(int tal1, int tal2) {
    return tal1 + tal2;
}

void println(string str) {
    cout << str << "\n";
    return;
}