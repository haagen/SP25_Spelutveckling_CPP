#pragma once

#include "animal.h"

class cat: public animal {
    public:
        cat(string name, unsigned char sex);
        unsigned char set_sex(unsigned char new_sex);
        void mjau();
    private:
        unsigned char checkSex(unsigned char sex);
};
