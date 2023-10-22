#ifndef MY_VECTOR_MATH_H
#define MY_VECTOR_MATH_H

typedef struct vec2f{
    // anonymous union
    union{
        struct {
            float x;
            float y;
        };
        float asArray[2];
    };

    // constructors
    vec2f() : x(0.0f), y(0.0f) {}
    vec2f(float xf, float yf) : x(xf), y(yf) {}
    

    float& operator[](int i){
        return asArray[i];
    }

} vec2f;


typedef struct vec3f{
    union{
        struct{
            float x;
            float y;
            float z;
        };
        float asArray[3];
    };

    // constructors
    vec3f() : x(0.0f), y(0.0f), z(0.0f) {}
    vec3f(float xf, float yf, float zf) : x(xf), y(yf), z(zf) {}

    float& operator[](int i){
        return asArray[i];
    }
} vec3f;


// Component-wise operations
vec2f operator+(const vec2f& lhs, const vec2f& rhs);
vec3f operator+(const vec3f& lhs, const vec3f& rhs);


vec2f operator-(const vec2f& lhs, const vec2f& rhs);
vec3f operator-(const vec3f& lhs, const vec3f& rhs);

vec2f operator*(const vec2f& lhs, float scale);
vec3f operator*(const vec3f& lhs, float scale);

/* Equality Comparison
    If every component of each vector is equal, the vectors are the equal.
    Due to floating point error, we can't compare floats directly. We use
    an error tolerance, called an epsilon test.

    Epsilon tests fall into one of two categories: absolute tolerance and 
    relative tolerance.

    Absolute tolerance comparison:
        if (Abs(x-y) <= EPISLON)

    #define ABSOLUTE(x,y) (fabs((x)-(y)) <= FLT_EPSILON)

    Reltaive tolerance comparison
        if( Abs(x-y) <= EPSILON * Max(Abs(x), Abs(y)))

    #define RELATIVE(x,y) \ 
    (fabsf((x)-(y)) <= FLT_EPSILON * Max(fabsf(x), fasbsf(y)))


    Absolute tolerance test when large numbers are compared.
    Relative tolerance test fails when small numbers are compared.  

 
    For equality, if either test is true, the values are equal.

    if  (Abs(x-y) <= absTol) OR
        (Abs(x-y) <= relTol * Max(Abs(x), Abs(y)))

    Combining the two expressions:

    if (Abs(x-y) <= Max(absTol, relTol * Max(Abs(x), Abs(y))))

    When absTol equals relTol,

    if (Abs(x-y) <= absTol * Max(1.0f, Abs(x), Abs(y)))


    https://realtimecollisiondetection.net/blog/?p=89#:~:text=%2F%2F%20Absolute%20tolerance%20comparison%20of%20x%20and%20y,relative%20tolerance%20test%20fails%20when%20they%20become%20small.  
    
    */

bool operator==(const vec2f& lhs, const vec2f& rhs);
bool operator==(const vec3f& lhs, const vec3f& rhs);

bool operator!=(const vec2f& lhs, const vec2f& rhs);
bool operator!=(const vec3f& lhs, const vec3f& rhs);


float dot(const vec2f& lhs, const vec2f& rhs);
float dot(const vec3f& lhs, const vec3f& rhs);

float magnitude(const vec2f& v);
float magnitude(const vec3f& v);

/* Distance between two points */
float distance(const vec2f& p1, const vec2f& p2);
float distance(const vec3f& p1, const vec3f& p2);

void normalize(vec2f& v);
void normalize(vec3f& v);

vec2f normalize(const vec2f& v);
vec3f normalize(const vec3f& v);

vec3f cross(const vec3f& lhs, const vec3f& rhs);

#endif 