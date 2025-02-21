#pragma once

#include <iostream>

using namespace std;

/*
 * Här defnierar vi hund-klassen (outside) eftersom implementation
 * och definition inte finnas på samma ställe.
 */
class dog {
public:
    // Attribut
    string name;
    string breed;
    int age;
    bool male;

    // Methods (functions)
    dog();
    dog(string name, string breed, int age, bool male);
    int birthday();
    bool breeding(dog d, dog** puppy);
    
};
