
#include <iostream>
#include <Windows.h>    // Behövs bara på Windows (inte på Mac)

using namespace std;

/*
    Detta är lösningsförslag till övning 2
*/
int main(int argc, char* argv[])
{
    // Skriv ut tecken med UTF8 (så att åäö fungerar)
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
  
    int myVar1 = 99;
    double myVar2 = 3.14;
    char myVar3 = 'A';
    bool myVar4 = true;
    string myVar5 = "Hello, World!";

    double y = 1 / 3;   // Detta är heltals division -> 0
    std::cout << "1 / 3 = " << y << "\n";
    double z = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    // i C++ har vi tillräckligt hög noggranhet så detta skall 1 (i Java blir det inte det)
    std::cout << "10 * 0.1 = " << z << "\n"; 
    
    if (myVar1 > myVar2) {
        cout << "Hej C++\n";
    }

    if (y > 0.0) {
        cout << "Det var konstigt!\n";
    } else {
        cout << "Vilken tur!\n";
    }

    if (z == 1.0) {
        cout << "Vad nu då!\n";
    }

    cout << "Udda eller jämnt\n";
    int tal;
    cin >> tal;
    if (tal % 2) {      // user 3 % 2 = 1 (sant)
        cout << "Talet är udda!\n";
    } else {
        cout << "Talet är jämnt!\n";
    }

    cout << "Betygsberäkning, var vänlig ange antalet poäng.\n";
    cout << "> ";
    int points;
    cin >> points;

    if (points >= 90) {
        cout << "A";
    } else if (points >= 80) {
        cout << "B";
    } else if (points >= 70) {
        cout << "C";
    } else if (points >= 60) {
        cout << "D";
    } else if (points >= 45) {
        cout << "E";
    } else {
        cout << "F";
    }
    cout << "\n";

    cout << "Mata in tal1: ";
    int tal1, tal2;
    cin >> tal1;
    cout << "Mata in tal2: ";
    cin >> tal2;

    if (tal1 > tal2) {
        cout << "tal1 (" << tal1 << ") > ";
        cout << "tal2 (" << tal2 << ")\n";
    } else {
        cout << "tal1 (" << tal1 << ") < ";
        cout << "tal2 (" << tal2 << ")\n";
    }

    cout << "Summan av talen är: " << (tal1+tal2) << "\n";
    cout << "Differensen av talen är: " << (abs(tal1-tal2)) << "\n";


    // Temperatur omvandling
    cout << "Vilket enhet är din temperatur (K, C, F): ";
    unsigned char unit;
    cin >> unit;

    bool validUnit = (unit == 'K' || unit == 'C' || unit == 'F');
    if (!validUnit) {
        cout << "Du angav en felaktig enhet!";
        return -1;
    }

    double userDegrees;
    cout << "Vad är din temperatur i grader " << unit << "? ";
    cin >> userDegrees;

    double degreesC = 0.0, degreesF = 0.0, degreesK = 0.0;
    
    if (unit == 'C') {
        degreesC = userDegrees;
        degreesF = (degreesC * 9.0/5.0) + 32.0;
        degreesK = degreesC + 273.15;
    }

    if (unit == 'F') {
        degreesF = userDegrees;
        degreesC = (degreesF - 32.0) * 5.0/9.0;
        degreesK = degreesC + 273.15;
    }

    if (unit == 'K') {
        degreesK = userDegrees;
        degreesC = degreesK - 273.15;
        degreesF = (degreesC * 9.0/5.0) + 32.0;
    }    

    cout << "Temperaturen\n";
    cout << "============\n";
    cout << " K = " << degreesK << "\n";
    cout << " C = " << degreesC << "\n";
    cout << " F = " << degreesF << "\n";
    
    return 0;
}
