#pragma once

#include "parent.h"

class child : public parent {
    public:
        int y;
        child(int x, int y);
        void my_method();
};
