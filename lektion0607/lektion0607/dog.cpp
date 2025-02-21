#include "dog.h"

dog::dog() {
    age = 0;
}

dog::dog(string name, string breed, int age, bool male) {
    this->name = name;
    this->breed = breed;
    this->age = age;
    this->male = male; 
}

int dog::birthday() {
    this->age++;
    return this->age;
}

bool dog::breeding(dog d, dog** puppy) {

    if (this->male == d.male) {
        return false;
    }

    *puppy = new dog(
        "Puppy " + this->name+"-"+d.name,
        this->breed,
        0,
        this->male
    );
    
    return true;
}
