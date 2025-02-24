#include "animal.h"

#include <iostream>

animal::animal(string name, unsigned char sex) {
    this->name = name;
    this->sex = checkSex(sex);
}

string animal::get_name() {
    return name;
}

int animal::get_age() {
    return age;
}

int animal::set_age(int new_age) {
    if (new_age >= 0 && new_age <= 200) {
        this->age = new_age;
    }
    return age;
}

unsigned char animal::get_sex() {
    return sex;
}

unsigned char animal::checkSex(unsigned char sex) {
    if ( sex == 'M' || sex == 'F' || sex == 'H') {
        return sex;        
    }
    return 'H';
}

unsigned char animal::set_sex(unsigned char new_sex) {
    // M, F, H
    sex = checkSex(new_sex);
    return sex;
}

void animal::info() {
    cout << class_name << " [ name: " << name << ", age: " << age << ", sex: " << sex << "]\n"; 
}


