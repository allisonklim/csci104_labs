#include "fermat.h"

#include <vector>
#include <cassert>
#include <random>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

// Calculates (base ^ exponent) % mod
std::uint32_t mod_exp(std::uint32_t base, std::uint32_t exponent, std::uint32_t mod) {
    // throw std::runtime_error{"Not implemented"};
    std::uint64_t x = 1;
    //r gets really big when it's r * r (line25)
    std::uint64_t r = base % mod;
    int lastDigit;
    while(exponent != 0){
        lastDigit = exponent % 2;    
        if(lastDigit == 1){
            x =  (x * r) % mod; 
        }
        r = (r * r)% mod; 
        exponent = (exponent / 2);
    }
    return static_cast<std::uint32_t>(x);
}

// Perform Fermat test on n.
// You should return true only if A^(n-1) % n == 1 for every A inside the tests vector
bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests) {
    // throw std::runtime_error{"Not implemented"};
    bool ferm = true; 
    for (int i=0; i<(int)tests.size(); i++){
        if(mod_exp(tests[i], n-1, n) == 1){
            //do nothing 
            continue; 
        }
        else{
            ferm = false; 
        }
    }
    return ferm;
}

