#include "Vec2f.hpp"


Vec2f::Vec2f(){}

Vec2f::Vec2f(float x, float y)
   : m_x(x), m_y(y)
{

}

float Vec2f::getX()const
{
   return m_x;
}

float Vec2f::getY()const
{
   return m_y;
}

void Vec2f::setX(float x)
{
   m_x = x;
}

void Vec2f::setY(float y)
{
   m_y = y;
}

Vec2f Vec2f::operator + (const Vec2f& rhs) const
{
   return Vec2f(m_x + rhs.m_x, m_y + rhs.m_y);
}

Vec2f Vec2f::operator - (const Vec2f& rhs) const
{
   return Vec2f(m_x - rhs.m_x, m_y - rhs.m_y);
}