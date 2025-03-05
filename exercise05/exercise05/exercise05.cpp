
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    // Övning 1
    int ettTal = 5;
    int* pekareTillEttTal = &ettTal;
    cout << "ettTal: " << ettTal << " pekareTillEttTal: " << *pekareTillEttTal << "\n";

    *pekareTillEttTal = 10;
    cout << "ettTal: " << ettTal << " pekareTillEttTal: " << *pekareTillEttTal << "\n";
    

    // Övning 2
    int myInteger[] = { 10, 19, 23, 76, -1 };
    int* myNumber = myInteger;  // Point to the first element

    cout << "myNumbers: ";
    while (*myNumber != -1) {
        if (*myNumber > 50) {   // Change all values in the array that are bigger than 50
            *myNumber = 50; 
        }
        cout << *myNumber << " ";
        myNumber++; // Moving the pointer to the next element in the array
    }
    cout << "\n";

    // Övning 3

    int myNewValue = 99;
    int* myValuePtr = &myNewValue;
    int** myValuePtrPtr = &myValuePtr;

    cout << "myNewValue: " << **myValuePtrPtr << "\n";
    **myValuePtrPtr = **myValuePtrPtr + 1; // Increase the value with one
    cout << "myNewValue: " << **myValuePtrPtr << " (" << myNewValue << ")\n";

    // Övning 4
    const int SIZE = 10;
    int* myNewArray = new int[SIZE];    // Allocate memory
    for (int i=0; i < SIZE; i++) {
        myNewArray[i] = (i+1) * (i+1);  // Fill the array with multiples of a value 
    }
    cout << "myNewArray: ";
    for (int i=0; i < SIZE; i++) {
        cout << myNewArray[i] << " ";   
    }
    cout << "\n";
    delete[] myNewArray;                // Free the memory
    myNewArray = nullptr;

    // Övning 5
    unique_ptr<int> myUniquePtr = make_unique<int>(100);
    shared_ptr<string> mySharedPtr = make_shared<string>("Hejsan SP25!");
    *myUniquePtr = *myUniquePtr * 2;        // Double the value of my pointer
    *mySharedPtr = "This is an example solution";
    cout << "The value of my uniqe ptr: " << *myUniquePtr << "\n";
    cout << "mySharedPtr: " << *mySharedPtr << "\n";

    shared_ptr<string> myCopiedSharedPtr = mySharedPtr;
    cout << "myCopiedSharedPtr: " << *myCopiedSharedPtr << "\n";
    cout << "Number of pointers: " << mySharedPtr.use_count() << "\n";

    mySharedPtr.reset();    // ?? What happens here? Frees up
    cout << "Number of pointers after reset: " << mySharedPtr.use_count() << "\n";

    // Övning 6
    cout << "How many numbers do you have? ";
    int myNumbers;
    cin >> myNumbers;
    if (myNumbers < 1 || myNumbers > 1000) {
        cout << "To many numbers! Please try again!\n";
        return -1;
    }
    myNewArray = new int[myNumbers];
    for (int i=0; i<myNumbers; i++) {
        cout << "Your " << (i+1) << " number: ";
        cin >> myNewArray[i];
    }
    
    double avg = 0, sum = 0;
    for (int i=0; i<myNumbers; i++) {
        sum += myNewArray[i];
    }
    avg = sum / myNumbers;
    sum = 0;
    // Calcualte the standard deviation
    for (int i=0; i<myNumbers; i++) {
        sum += pow(myNewArray[i] - avg, 2); // (x - m)^2    
    }
    double s = sqrt(sum / (myNumbers - 1));

    cout << "The average of you numbers is: " << avg << "\n";
    cout << "The standard deviation is: " << s << "\n";
    delete[] myNewArray;
    myNewArray = nullptr;
    
    return 0;
}
