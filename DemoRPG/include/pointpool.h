#pragma once
#include <cstdint>

class PointPool {
    public:
        PointPool(uint16_t curr_val = 1, uint16_t max_val = 1);

        bool setMax(uint16_t n_max);
        bool setVal(uint16_t n_val);
        uint16_t getMax() const;
        uint16_t getCurrent() const;
        void reduce(uint16_t i_val);
        void increase(uint16_t i_val);
    private:
        uint16_t currentVal;
        uint16_t maxVal;

};