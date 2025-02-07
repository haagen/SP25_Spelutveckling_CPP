
#include <iostream>
#include <string>
#include <windows.h>    // För SetConsoleCP* metoderna

using namespace std;

int main(int argc, char* argv[])
{

    // I Windows (ej Mac) behöver vi sätta vilken teckentabell som
    // vi vill använda för att läsa och skriva från konsollen.
    // UTF8 är modern och bra!
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    // Declare variables
    int myInt = 8;
    float myFloat = 2.2f;   // We use the f to specify that it is a float - defaults to decimal
    double myDouble = 3.0;
    char myChar = 'a';
    bool myBool = true; // false

    cout << "myInt: " << myInt << "\n";
    cout << "myFloat: " << myFloat << "\n";
    cout << "myDouble: " << myDouble << "\n";
    cout << "myChar: " << myChar << "\n";
    cout << "myBool: " << myBool << "\n"; 
    
    int myOtherInt = myFloat;   // Implicit (narrowing) cast - loose information
    cout << myOtherInt << " = " << myFloat << "?\n";
    myFloat = myInt;            // Implicit (widening) cast
    cout << myFloat << " = " << myInt << "?\n";

    // Aritmetiska uttryck
    myInt = myInt + 1;
    // What is the difference between
    cout << myInt << "\n";  // 9
    myInt++;
    cout << myInt << "\n";  // 10
    ++myInt;
    cout << myInt << "\n";  // 11

    int tal1 = myInt++;
    int tal2 = ++myInt;
    cout << tal1 << "\n";   // 11
    cout << tal2 << "\n";   // 13
    
    string fullname;
    cout << "Vad är ditt fulla namn? ";
    //cin >> fullname;      // Avslutats vid första mellanslag
    getline(cin, fullname);  // Avslutas vid radbrytning
    cout << "Hej " << fullname << ", vad kul att se dig!\n";

    string textStr = "1337";
    string textStr2 = textStr + "1";    // 13371
    1;
    int konverteradeInt = stoi(textStr);  // 1337
    konverteradeInt += 1;  // 1338

    cout << "textStr2: " << textStr2 << " konverteradeInt: " << konverteradeInt << "\n";

    // BMI (Body Mass Index): bmi = weight / length^2
    double weight, length;
    cout << "What's your weight? \n";
    cin >> weight;
    cout << "What's your length? \n";
    cin >> length;

    // Calculate the BMI value
    double bmi = weight / (length * length);
    cout << "Your BMI is " << bmi << "\n";

    // If a person has a BMI between 18.5 and 24.9 he/she is considered normal weight
    if ( bmi >= 18.5 && bmi <= 24.9 ) {
        cout << "Your BMI is within the bounds for whats considered \"normal\"!\n";
    } else {
        if (bmi < 18.5) {
            cout << "Your BMI is below whats considered \"normal\"!\n";
        } else if (bmi > 24.9) {
            cout << "Your BMI is above whats considered \"normal\"!\n";
        }   
    }

    const double BMI_LOW = 18.5;
    const double BMI_HIGH = 24.9;
    const double BMI_MID = BMI_LOW + (BMI_HIGH - BMI_LOW)/2;
    // Calculate optimalWeight
    double optimalWeight = BMI_MID * length * length;
    cout << "Your optimal weight is " << optimalWeight << " (BMI: " << BMI_MID << ") \n";
    
    
    return 0;
}
