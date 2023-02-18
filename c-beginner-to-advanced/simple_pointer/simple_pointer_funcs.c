#include "simple_pointer_funcs.h"

//call by value:
//local copy of the input !!!value!!!
float addWithFloat(float z_func) // 0x61ff10
{
    printf("Add: 0x%x\n", &z_func);
    z_func += 3.0f;

    return z_func;
}

// call by reference:
// input is the argument variable
void sub(float* z_func) // 0x61ff2c
{
    printf("Sub: 0x%x\n", z_func);
    *z_func = *z_func - 3.0f;
}

int binom(int* a, int* b)
{
    return (*a) * (*a) + 2 * (*a) * (*b) + (*b) * (*b);
}

void add(double* value1, double* value2, double add_value)
{
    *value1 += add_value; // * content (value) of the variable that is pointed to
    *value2 += add_value; // * content (value) of the variable that is pointed to
}