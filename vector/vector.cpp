#include "vector.h"
#include <cmath>
#include <cfloat>       // FLT_EPSILON

// FLT_EPSILON - difference between 1.0 and the next representable value for float
#define CMP(x, y)                    \
    (fabsf( (x) - (y) ) <= FLT_EPSILON * \
      fmaxf(1.0f,                    \
      fmaxf(fabsf(x), fabsf(y)))     \
   )



vec2f operator+(const vec2f& lhs, const vec2f& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

vec3f operator+(const vec3f& lhs, const vec3f& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}


vec2f operator-(const vec2f& lhs, const vec2f& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

vec3f operator-(const vec3f& lhs, const vec3f& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}



vec2f operator*(const vec2f& lhs, float scale)
{
    return { lhs.x * scale, lhs.y * scale };
}

vec3f operator*(const vec3f& lhs, float scale)
{
    return { lhs.x * scale, lhs.y * scale, lhs.z * scale };
}


bool operator==(const vec2f& lhs, const vec2f& rhs)
{
    return CMP(lhs.x, rhs.x) && CMP(lhs.y, rhs.y);
}

bool operator==(const vec3f& lhs, const vec3f& rhs)
{
    return CMP(lhs.x, rhs.x) && CMP(lhs.y, rhs.y) && CMP(lhs.z, rhs.z);
}


bool operator!=(const vec2f& lhs, const vec2f& rhs)
{
    return !(lhs == rhs); 
}

bool operator!=(const vec3f& lhs, const vec3f& rhs)
{
    return !(lhs == rhs); 
}

/* Dot product represents directional relation of two
   vectors.

   Positive - vectors pointing in same direction
   Negative - vectors pointing in opposite directions
   Zero - vectors are perpendicular

   Geometric definition
    A dot B = magnitude(A) magnitude(B) cos theta

   where theta is the angle between the two vectors.
*/
float dot(const vec2f& lhs, const vec2f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}


float dot(const vec3f& lhs, const vec3f& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

/* Magnitude - vector length
*/
float magnitude(const vec2f& v)
{
    return sqrtf(v.x*v.x + v.y * v.y);
}

float magnitude(const vec3f& v)
{
    return sqrtf(v.x*v.x + v.y * v.y + v.z * v.z);
}


/* Distance between two points 

   Length of vector distance between two points
*/
float distance(const vec2f& p1, const vec2f& p2)
{
    vec2f t = p1 - p2;
    return magnitude(t);
}

float distance(const vec3f& p1, const vec3f& p2)
{
    vec3f t = p1 - p2;
    return magnitude(t);
}

/* Scale vector components such that vector has length 1 */
void normalize(vec2f& v)
{
    float m = magnitude(v);
    v.x = v.x / m;
    v.y = v.y / m;
}

void normalize(vec3f& v)
{
    float m = magnitude(v);
    v.x = v.x / m;
    v.y = v.y / m;
    v.z = v.z / m;
}

vec2f normalize(const vec2f& v)
{
    float m = magnitude(v);
    return vec2f(v.x/m, v.y/m);
}

vec3f normalize(const vec3f& v)
{
    float m = magnitude(v);
    return vec3f(v.x/m, v.y/m, v.z/m);
}



vec3f cross(const vec3f& lhs, const vec3f& rhs)
{
    vec3f v;
    v.x = lhs.y * rhs.z - lhs.z * rhs.y;
    v.y = lhs.z * rhs.x - lhs.x * rhs.z;
    v.z = lhs.x * rhs.y - lhs.y * rhs.x;
    return v;
}


