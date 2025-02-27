#pragma once

class dice {
    public:
        dice(int min, int max);
        int roll();
    private:
        int min, max;
};
