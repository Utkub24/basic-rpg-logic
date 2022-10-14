#include "pointpool.h"

PointPool::PointPool(uint16_t curr_val, uint16_t max_val) 
    : currentVal(curr_val), maxVal(max_val) {
        if(curr_val > max_val) currentVal = max_val; 
    }

bool PointPool::setMax(uint16_t n_max) {
    if(n_max < 1) return false;

    maxVal = n_max;

    if(currentVal > maxVal) currentVal = maxVal;

    return true;
}

bool PointPool::setVal(uint16_t n_val) {
    if(n_val < 1) return false;

    currentVal = n_val;

    if(n_val > maxVal) currentVal = maxVal;

    return true;
}

uint16_t PointPool::getMax() const { return maxVal; }
uint16_t PointPool::getCurrent() const { return currentVal; }

void PointPool::reduce(uint16_t i_val) {
    if(i_val > currentVal) {
        currentVal = 0;
        return;
    }

    currentVal -= i_val;
}

void PointPool::increase(uint16_t i_val) {
    if(i_val + currentVal > maxVal) {
        currentVal = maxVal;
        return;
    }

    currentVal += i_val;
}
