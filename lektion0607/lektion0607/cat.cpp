#include "cat.h"
#include <iostream>

cat::cat(string name, unsigned char sex):animal(name, sex) {
    animal::set_sex(checkSex(sex));
    class_name = "cat";
}

unsigned char cat::checkSex(unsigned char new_sex) {
    if (new_sex == 'M' || new_sex == 'F') {
        return new_sex;
    }
    return 'F';
}

unsigned char cat::set_sex(unsigned char new_sex) {
    return animal::set_sex(checkSex(new_sex));
}

void cat::mjau() {
    std::cout << "MJAUUUU!\n";
}
