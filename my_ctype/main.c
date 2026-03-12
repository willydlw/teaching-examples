#include <ctype.h>
#include <limits.h>
#include <stdio.h>

// Lookup table for all ASCII characters 
// 1 = isspace, 0 = not isspace
static const unsigned char isspace_lut[256] = {
    [' '] = 1, ['\t'] = 1, ['\n'] = 1, ['\v'] = 1, ['\f'] = 1, ['\r'] = 1
};

// Fucntioi Prototype
int my_isspace(int c);
int my_isspace_lut(int c);

typedef enum {
    SPACE = (int) ' ',
    TAB =   (int) '\t',
    LF =    (int) '\n',
    VT =    (int) '\v',
    FF =    (int) '\f',
    CR =    (int) '\r'
} WhiteSpace;

int my_isspace_lut(int c){
    // Ensure c is valid unsigned char index (0-255)
    // Works for EOF (-1) is cast to 255 which is non-whitespace
    // -1 is 0xffff ffff
    return isspace_lut[(unsigned char)c];
}


int my_isspace(int c)
{
    switch(c){
        case SPACE:
        case TAB:
        case LF:
        case VT:
        case FF:
        case CR:
            return 1;
        default:
            return 0;
    }
}


void test(int c)
{
    int actual    = my_isspace_lut(c); //my_isspace(c);
    int expected  = isspace(c);
    // isspace returns non-zero value, cast non-zero value to 1 
    expected = expected? 1 : 0;
    if(actual != expected){
        fprintf(stderr, "character value: %d, actual: %d != expected: %d\n",
                c, actual, expected);
    }
}

void run_tests(void)
{
    for(int i = 0; i <= UCHAR_MAX; i++){
        test(i);
    }

    test(EOF);
}

int main(void)
{
    run_tests();
    return 0;
}
