#pragma once 
#include <random>

class RandomNumberGenerator {
    public:

    RandomNumberGenerator();

    // returns uniformly distributed random number
    // in range [min, max] (inclusive)
    int getRandomInt(int min, int max);

    private:

    std::mt19937 m_engine;        // Mersenne Twister engine 


};