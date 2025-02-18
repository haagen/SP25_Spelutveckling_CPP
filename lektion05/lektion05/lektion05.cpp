
#include <iostream>

using namespace std;

/*
 *  Argumenten i en funktion är kopior, därför spara
 *  försvinner ändringar till dessa efter att funktionen
 *  returnerat (kopiorna ligger på stacken).
 *  En pekare kan avrefereras och ändras på eftersom pekaren
 *  pekar på en adress och därför är adressen kopierad. 
 */
bool fixName(string* name) {
    cout << "fixName: " << *name << "\n";
    *name = "Martin";
    return true;
}

/*
 * När vi allokerar data så får vi en ny adress,
 * vill vi då ändra en pekare från en annan funktion
 * kan vi använda en dubbelpekare - dvs en pekare till
 * en pekare. 
bool createWorld(int seed, void** myWorld) { 
}
*/

void memory() {
    int i = 42;
    int* iPtr = &i;
    int** iPtrPtr = &iPtr;

    cout << "iPtr = " << iPtr << " (" << *iPtr << ") \n";
    cout << "iPtrPtr = " << iPtrPtr << " (" << *iPtrPtr << " (" << **iPtrPtr << "))\n";

    string name = "Farid";
    fixName(&name);
    cout << "The name: " << name << "\n";

    int iArr[] = { 10, 20, 30, 40, 50 };
    iPtr = &iArr[0];
    for (int k=0; k<5; k++, iPtr++) {
        cout << "iPtr = " << iPtr << " (" << *iPtr << ") \n";
        //iPtr++; // till nästa integer i arrayen
    }
    
    int* dynamicInt = new int;  // Allokera minne för en integer
    *dynamicInt = 36;
    cout << "dynamicInt = " << dynamicInt << " (" << *dynamicInt << ")\n";
    delete dynamicInt;          // Frigör (lämna tillbaka minnet)
    dynamicInt = nullptr;

    // En unique_ptr får bara finnas en gång dvs
    // en unik referens. När den försvinner ur
    // minnet frigörs det allokerade minnet. 
    unique_ptr<int> uniqueInt = make_unique<int>(42);
    cout << "Value of uniqueInt: " << *uniqueInt << "\n";
    *uniqueInt += 42;
    cout << "Value of uniqueInt: " << *uniqueInt << "\n";
    uniqueInt = nullptr;

    shared_ptr<int> sharedInt = make_shared<int>(333);
    cout << "Value of sharedInt: " << *sharedInt << "\n";
    *sharedInt += 111;
    cout << "Value of sharedInt: " << *sharedInt << "\n";
    shared_ptr<int> sharedIntCopy = sharedInt;
    *sharedIntCopy += 111;
    *sharedInt += 111;
    cout << "Value of sharedInt: " << *sharedInt << "\n";
    cout << "Value of sharedIntCopy: " << *sharedIntCopy << "\n";
    cout << "Number of refrences: " << sharedInt.use_count() << "\n";
    sharedInt = nullptr;
    cout << "Number of references (sharedCopy): " << sharedIntCopy.use_count() << "\n";
    
}

void debugging() {
    
    // Allocate memory for 5 elements
    int* arr = new int[5];

    // Bad loop: 'i' increments from 0 to 5, that gives 6 iterations (index 0-5).
    // The array only as place for 0 to 4 (5 iterations)
    for (int i = 0; i <= 5; i++) {
        arr[i] = i * 2;
    }
    
    // Print the values 
    cout << "Array values: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Free the allocated memory
    delete[] arr;
}

int main(int argc, char* argv[])
{
    
    //memory();
    debugging();
    
    return 0;
}
