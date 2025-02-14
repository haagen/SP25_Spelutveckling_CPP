
#include <iostream>
#include <vector>

using namespace std;

void array_examples() {

    cout << "Array example 1: \n";
    int myNumber[5];    // = { 1, 2, 3, 4, 5 };
    for (int i=0; i<5; i++) {
        myNumber[i] = (i+1)*(i+1);
    }

    unsigned int size = sizeof(myNumber) / sizeof(myNumber[0]);
    for (int i=0;i<size;i++) {
        cout << "On position " << i << " in the array we have the number: " << myNumber[i] << "\n";
        myNumber[i] = 0; 
    }

    cout << "Array example 2: \n";
    int myOtherNumbers[7]; // = { 23, 42, 7, 16, 8, 34, 77 };
    for (int i=0;i<7;i++) {
        cout << "Lotto number " << (i+1) << " > ";
        cin >> myOtherNumbers[i];
    }
    for (int tal: myOtherNumbers) {
        if (tal > 31) { // 31 is the max lotto number
            cout << tal << " is an invalid number. Please change your...\n";
        }
    }
    
}

void vector_examples() {
    vector<int> my_vector = { 1, 2, 3, 4, 5 };
    cout << "The element on index 1 (position 2) is " << my_vector[1] << "\n";

    my_vector.push_back(6);
    cout << "My vector: ";
    for (int tal : my_vector) {
        cout << tal << " ";
    }
    cout << "\n";

    cout << "Out vector has the size(): " << my_vector.size() << "\n";
    my_vector.clear();  // Empty the vector
    cout << "Out vector has the size(): " << my_vector.size() << "\n";
    
}

void iterator_example() {

    vector<string> my_vector = { "Johan", "Martin", "Pelle", "Felippa" };

    cout << "Queue to the Microwave: ";
    vector<string>::iterator strItr = my_vector.begin();
    while (strItr != my_vector.end()) {
        cout << *strItr << " ";
        ++strItr;
    }
    cout << "\n";

    // Elin is very hungry - and makes her way to the first place in the queue
    auto firstPlaceItr = my_vector.begin();
    my_vector.insert(firstPlaceItr, "Elin");

    strItr = my_vector.begin();
    cout << "Queue to the Microwave: ";
    while (strItr != my_vector.end()) {
        cout << *strItr << " ";
        ++strItr;
    }
    cout << "\n";

    // Martin leaves the queue
    strItr = my_vector.begin();
    while (strItr != my_vector.end()) {
        if (*strItr == "Martin") {
            my_vector.erase(strItr);
            break;
        }
        ++strItr;
    }

    cout << "Queue to the Microwave: ";
    strItr = my_vector.begin();
    while (strItr != my_vector.end()) {
        cout << *strItr << " ";
        ++strItr;
    }
    cout << "\n";    
    
}

int main(int argc, char* argv[])
{

    cout << "Choose the example you want to run: \n";    
    cout << "1. Array examples\n";
    cout << "2. Vector examples\n";
    cout << "3. Iterator examples\n";

    cout << "> ";

    unsigned char selection = 0;
    cin >> selection;

    switch (selection) {
    case '1':
        array_examples();
        break;
    case '2':
        vector_examples();
        break;
    case '3':
        iterator_example();
        break;
    }
    
    return 0;
}
