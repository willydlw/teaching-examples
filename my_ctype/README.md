# Reinventing the Wheel - Character Handling Functions

Goal: write our own version of ctype library functions as a good practice exercise and to better understand how the library functions work.

## isspace 

``` int isspace(int c); ```


Checks if the given character is either
- A standard white-space character

| Character | Hex value | Description |
| --- | --- | --- |
| ' '  | 0x20 | space |
| '\t' | 0x09 | horizontal tab |
| '\n' | 0x0a | newline | 
| '\v' | 0x0b | vertical tab |
| '\f' | 0x0c | form feed |
| '\r' | 0x0d | carriage return |

- Or a locale-specific white-space character 

The behavior is undefined if character value is not representable as unsigned char and is not equal to EOF.

**Parameters** 
c   Character to be checked, casted to an ***int***, or EOF 

**Return Value**
A value different from zero (i.e., true) if **c** is a white-space character. Zero (i.e., false) otherwise.

