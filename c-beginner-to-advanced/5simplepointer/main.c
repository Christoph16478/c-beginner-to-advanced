#include <stdio.h>
#include <math.h>

#define cola 0
#define icetea 1
#define water 2
#define coffee 3

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

void add(double* value1, double* value2, double add_value)
{
    *value1 += add_value; // * content (value) of the variable that is pointed to
    *value2 += add_value; // * content (value) of the variable that is pointed to
}

int main()
{
    int selection;
    printf("Pls enter a valid code for any drink!\n");
    scanf_s("%d", &selection);
    switch (selection)
    {
        case cola: printf("Cola!\n"); break;
        case icetea: printf("IceTea!\n"); break;
        case water: printf("Water!\n"); break;
        case coffee: printf("Coffee!\n"); break;
        default: printf("You did not enter a valid number!");
    }
    int a = 4;
    printf("%d", a);
    int b = 3;
    printf("%d", b);
    int c = 0;
    printf("%d", c);
    // 16 + 2 * (12) + 9
    // 25 + 24 = 49
    c = binom(&a, &b);
    printf("%d", c);

    a = 4;
    b = 3;
    c = 0;
    // 16 + 2 * (12) + 9
    // 25 + 24 = 49
    c = binom(&a, &b);
    printf("%d", c);

    int my_value = 1337;
    printf("Value of my_value: %d\n", my_value);
    printf("Memory address of my_value: %p\n", &my_value);

    int* my_pointer = &my_value;
    printf("Value of my_pointer: %p\n", my_pointer);
    printf("Value of the reference of my_pointer: %d\n", *my_pointer);
    printf("Memory address of my_pointer: %p\n", &my_pointer);

    float z_main = 1.0f; // 0x61ff2c
    printf("Main Addr.: 0x%x\n", &z_main);

    // Call by Value
    z_main = addWithFloat(z_main);
    printf("Main Val.: %f\n", z_main);

    // Call by Reference
    sub(&z_main);
    printf("Main Val.: %f\n", z_main);

    // Main (3)
    // --------
    float val_main = 0.0f;
    printf("Memory address of val_main: %p\n", &val_main);

    printf("%f\n", val_main);
    val_main = addWithFloat(val_main);
    printf("%f\n", val_main);
    sub(&val_main);
    printf("%f\n", val_main);

    // Main (4)
    // --------
    double my_value1 = 3.0;
    double my_value2 = 2.0;
    double my_add_value = 1.3;

    add(&my_value1, &my_value2, my_add_value);

    printf("%lf\n", my_value1);
    printf("%lf\n", my_value2);

    // Main (6)
    // --------
    a = 1; // 0x61ff20
    b = 2;
    c = 3;

    // p_d points to the memory location of variable a
    // *p_d is the content of the memory location
    int* p_d = &a;
    int* p_e = &b;
    int* p_f = &c;

    // p_d = 2 * p_e + 3 * p_f
    // *p_d = 2 * 2 + 3 * 3 = 13
    *p_d = 2 * *p_e + 3 * *p_f;
    p_d = &b;
    p_f = &a;

    // p_d -> b, p_f -> a, p_e -> b
    // 2, 13
    *p_e = *p_d + *p_f; // the content of the memory location of p_e is set to 15

    printf("%d\n", a);
    printf("%d\n", *p_d); // ?
    printf("%d\n", *p_e);
    printf("%d\n", *p_f);

    return 0;
}
