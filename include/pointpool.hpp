#pragma once

class PointPool {
  public:
    bool setMax(uint16_t n_max) {
      if(n_max < 1)
        return false;
      
      maxVal = n_max;

      if(currentVal > maxVal)
        currentVal = maxVal;

      return true;
    }    

    bool setVal(uint16_t n_val) {
      if(n_val < 1)
        return false;

      currentVal = n_val;

      if(n_val > maxVal)
        currentVal = maxVal;

      return true;
    }

    uint16_t getMax() {
      return maxVal;    
    }

    uint16_t getCurrent() {
      return currentVal;
    }  
  
    void reduce(uint16_t i_val) {
      if (i_val > currentVal) {
        currentVal = 0;
        return;
      }
      currentVal -= i_val;

    }

    void increase(uint16_t i_val) {
      if (i_val + currentVal > maxVal) {
        currentVal = maxVal;  
        return;
      }

      currentVal += i_val;
    }

    PointPool() { currentVal = 1; maxVal = 1; }
    PointPool(uint16_t curr_hp, uint16_t max_hp) {
      maxVal = max_hp;
      currentVal = curr_hp;
      if (currentVal > max_hp)
        currentVal = maxVal;
    }

  private:
    uint16_t currentVal;
    uint16_t maxVal;
};