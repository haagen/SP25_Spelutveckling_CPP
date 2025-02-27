#include "animal.h"

#include <iostream>

animal::animal(string name, unsigned char sex) {
    this->name = name;
    this->sex = sex;
}

string animal::get_name() {
    return this->name;
}

int animal::get_age() {
    return this->age;
}

int animal::set_age(int age) {
    if (age > 0) {
        this->age = age;
    }
    return age;
}

unsigned char animal::checkSex(unsigned char sex) {
    if (sex == 'M' || sex == 'F' || sex == 'H') {
        return sex;
    }
    return 'H'; // default to H
}

unsigned char animal::getSex() {
    return this->sex;
}

unsigned char animal::setSex(unsigned char sex) {
    this->sex = this->checkSex(sex);
    return this->sex;
}

void animal::info() {
    cout << this->class_name << " [name: " << this->name << ", age: " << this->age << ", sex: " << this->sex << "]\n";
}






