
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

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

void iterator_examples() {

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

void list_examples() {
    
    list<double> lista = { 1.81, 1.83, 1.69, 1.68, 1.60, 1.83 };

    double total_length = 0;
    for (double l: lista) {
        total_length += l;
    }

    cout << "The average lenght is: " << (total_length / lista.size()) << "\n";

    lista.sort();
    auto it = lista.begin();
    cout << "The shortest person in the list: " << *it << "\n";
    it = lista.end(); --it;
    //lista.reverse(); it = lista.begin();
    cout << "The tallest person in the list: " << *it << "\n";
    
}

void map_examples() {
    map<int, string> country_code_to_name;

    country_code_to_name[46] = "Sverige";
    country_code_to_name[45] = "Danmark";
    country_code_to_name[39] = "Italien";
    
    int country_code;
    cout << "What is your country code? ";
    cin >> country_code;

    if (country_code_to_name.count(country_code) == 0) {
        cout << "We don't know that country code!\n";
        cout << "We have these countries:\n";
        for (auto pair : country_code_to_name) {
            cout << pair.first << ": " << pair.second << "\n";
        }
        return;
    }

    cout << "Your country is " << country_code_to_name[country_code] << "\n";
}

void set_examples() {
    set<string> countries;

    string country;
    do {
        cout << "Ange ett land: ";
        cin >> country;
        countries.insert(country);
    } while (country != "0");

    cout << "Countries in out set: \n";
    for (auto c : countries) {
        cout << c << "\n";
    }

    if (countries.count("Danmark") > 0) {
        cout << "We found Danmark in the set\n";
    } else {
        cout << "We could not find Danmark in the set\n";
    }
    
}

int main(int argc, char* argv[])
{

    cout << "Choose the example you want to run: \n";    
    cout << "1. Array examples\n";
    cout << "2. Vector examples\n";
    cout << "3. Iterator examples\n";
    cout << "4. List examples\n";
    cout << "5. Map examples\n";
    cout << "6. Set examples\n";

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
        iterator_examples();
        break;
    case '4':
        list_examples();
        break;
    case '5':
        map_examples();
        break;
    case '6':
        set_examples();
        break;
    }
    
    return 0;
}
