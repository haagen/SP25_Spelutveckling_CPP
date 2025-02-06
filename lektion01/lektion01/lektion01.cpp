/*
 *  Detta är en fler-rads-kommentar. Den ignoreras av
 *  kompilatorn. Detta är ett sätt att dokumentera koden.
 *
 *
 *  
 */

// En-rads-kommentar. Kommentaren slutar när raden slutar. 

#include <iostream>
#include <ostream>

// Vi vill använda std namnrymden som standard
// så att vi slipper skriva std:: 
using namespace std;

int main(int argc, char* argv[])
{
    //std::cout << "Hello, World!\n";
    cout << "Hello, World!\n";

    // Vi kan skapa variabler
    int age = 18;           // heltal
    string name = "Martin"; // sträng
    double xp = 12.23;      // decimaltal

    // Det går att skriva ut variabler på skärmen
    cout << "Name: "<< name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Xp: " << xp << "\n";

    string petName;
    double petWeight;

    cout << "Whats your pet's name?\n";
    cin >> petName;
    cout << "Whats your pet's weight?\n";
    cin >> petWeight;

    const double MAX_WEIGHT = 100.0;
    double buffert = MAX_WEIGHT - petWeight;

    if (buffert >= 0) {
        cout << petName << " was able to cross the bridge!\n";
    } else {
        cout << petName << " better know how to swim...\n";
    }

    // Return 0 ( == okay, inget gick fel)
    return 0;
}
