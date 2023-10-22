#include "vector.h"

#include <iostream>


int main()
{
    // initialization and access example
    #if 1

    vec3f v = {1.0f, 2.0f, 3.0f};

    std::cout << "x: " << v.x << "\n";
    std::cout << "x: " << v.asArray[0] << "\n";
    std::cout << "x: " << v[0] << "\n";

    #endif 

    return 0;
    
}