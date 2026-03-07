#include "randomNumberGenerator.h"
#include <chrono>


RandomNumberGenerator::RandomNumberGenerator() : 
    m_engine(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()))

    { /* intentionally blank */ }


 int RandomNumberGenerator::getRandomInt(int min, int max)
 {
    // Define distribution. (range is inclusive [min, max])
    std::uniform_int_distribution<int> dist(min, max);
    return dist(m_engine);      // use engine to generate a number
 }