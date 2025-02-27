#pragma once

#include <string>
using namespace std;

class animal {
public:
    // Methods
    animal(string name, unsigned char  sex);
    string get_name();
    int get_age();
    int set_age(int age);
    unsigned char getSex();
    unsigned char setSex(unsigned char sex);
    void info();
    
private:
    // Attributes
    string name;
    int age = 0;
    unsigned char sex;  // M, F, H

    // Methods
    static unsigned char checkSex(unsigned char sex);    

protected:
    string class_name = "animal";


};
