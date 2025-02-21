
#include <iostream>
#include "dog.h"

using namespace std;

/*
 * Sättet som Car är definierad här kallas för "inside" eftersom definition
 * och implementation (hur / kod) finns på samma ställe.
 */
class car {
public:
    string make;
    string model;
    string color;
    int year;
    int max_speed;
    int current_speed = 0;

    car() {
        max_speed = 0;
        this->year = 0;
    }

    car(string make, string model, string color, int year, int max_speed) {
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
        this->max_speed = max_speed;
    }

    void honk() {
        cout << "TUUT TUUT!\n";
    }

    int accelerate(int speed_change) {
        this->current_speed += speed_change;
        if (current_speed > max_speed) {
            this->current_speed = max_speed;
        }
        return this->current_speed;
    }

    int slow(int speed_change) {
        current_speed -= speed_change;
        if (current_speed < 0) {
            current_speed = 0;
        }
        return current_speed;
    }
    
};


// Examples from lesson 1 in OOP
void basic_oop() {
    car fiat(
        "Fiat",
        "Punto",
        "Red",
        1999,
        135
    );

    car* jeep = new car(
        "Suzuki",
        "Samurai",
        "Black",
        1987,
        85
    );

    cout << "Fiat modell: " << fiat.model << "\n";
    cout << "Jeep: " << jeep->make << ", " << jeep->model << "\n";

    jeep->honk();   // Jeep är skapad med new -- altså en pekar, använd pil-notation
    fiat.honk();    // Fiat är skapad på stackan -- ingen pekare, använd punk-notation

    cout << "The current speed of the Jeep is: " << jeep->current_speed << "\n";
    cout << "The current speed of the Jeep is: " << jeep->accelerate(45) << "\n";
    cout << "The current speed of the Jeep is: " << jeep->accelerate(90) << "\n";
    cout << "The current speed of the Jeep is: " << jeep->slow(81) << "\n";
    cout << "The current speed of the Jeep is: " << jeep->slow(25) << "\n";

    /*
    cout << "How much do you want to accelearate? ";
    int speed_change = 0;
    cin >> speed_change;
    cout << "The current speed of the Jeep is: " << jeep->accelerate(speed_change) << "\n";
    */
    delete jeep;

    dog* fido = new dog("Fido", "Poodle", 12, false);
    dog* plutten = new dog("Plutton", "Daschhound", 9, false);
    dog* pucko = new dog("Pucko", "Border Collie", 5, true);
    dog* puppy = nullptr;

    if (fido->breeding(*plutten, &puppy)) {
        cout << "Fido and Plutten got a puppy: " << puppy->name << "\n";
        delete puppy;
        puppy = nullptr;
    } else {
        cout << "Fido and Plutten didn't get a puppy\n";
    }

    if (fido->breeding(*pucko, &puppy)){
        cout << "Fido and Pucko got a puppy: " << puppy->name << "\n";
        delete puppy;
        puppy = nullptr;
    } else {
        cout << "Fido and Pucko didn't get a puppy\n";
    }
    
}


int main(int argc, char* argv[])
{

    basic_oop();
    
    return 0;
}
