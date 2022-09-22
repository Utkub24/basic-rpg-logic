#include "random.h"
#include <chrono>
#include <random>

namespace Random {
    uint16_t NTK(uint16_t n, uint16_t k) {
        static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) }; 
        static std::mt19937 mgen(ss);

        // check if n <= k
        if(n <= k) {
            std::uniform_int_distribution<std::mt19937::result_type> ntkd(n, k);
            return ntkd(mgen);
        } else { // else n > k, switch n <-> k
            std::uniform_int_distribution<std::mt19937::result_type> ntkd(k, n);
            return ntkd(mgen);
        }

    }

}