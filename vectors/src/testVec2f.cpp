#include <cassert>
#include "Vec2f.hpp"

void test_default_constructor()
{
   Vec2f v1;
   assert(v1.getX() == 0.0f && v1.getY() == 0.0f); 
}

void test_other_constructor(float x, float y)
{
   Vec2f v1(x,y);
   assert(v1.getX() == x && v1.getY() == y); 
}

void test_setters(float x, float y)
{
   Vec2f v1;
   v1.setX(x);
   v1.setY(y);
    assert(v1.getX() == x && v1.getY() == y); 
}


int main()
{
   test_default_constructor();
   test_other_constructor(1.0f, 3.5f);
   test_other_constructor(2.1f, 10.0f/3.0f);

   test_setters(7.59f, -13.48);

   return 0;
}