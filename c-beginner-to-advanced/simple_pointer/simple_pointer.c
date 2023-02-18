#include <stdio.h>
#include <math.h>
#include "simple_pointer_funcs.c"

#define cola 0
#define icetea 1
#define water 2
#define coffee 3

int array1[] = { 10,20,30,40,50,60,70,80,90,100 };
int array2[] = { 38, 27, 87, 63, 59, 223, 132, 1, 19, 7 };

int add_simple_pointer(int a, int b) { return a + b; }
int sub_simple_pointer(int a, int b) { return a - b; }
int mult_simple_pointer(int a, int b) { return a * b; }
int div_simple_pointer(int a, int b) { return a / b; }

/// Array of pointers to functions
int (*fpArr[])(int, int) = { &add_simple_pointer,&sub_simple_pointer,&mult_simple_pointer,&div_simple_pointer };

// performs the given operation on elements of the arrays
int* performOp(int* a, int* b, int size, int (*f)(int, int));

// displays the elements of an array
void display(int* x, int size);

// performs the given operation on all elements of the arrays A and B
int* performOp(int* a, int* b, int size, int (*f)(int, int))
{
    int* c = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        c[i] = (*f)(a[i], b[i]);
    }

    return c;
}

// function for displaying the results stored in array x
void display(int* x, int size)
{

    if (x == NULL)  return;

    for (int i = 0; i < size; i++) {
        printf("%d   ", x[i]);
    }

    printf("\n");
}

int main()
{
    /* function pointers */

    int choice = 0;

    // size of the array
    unsigned int size = 0;

    int* result = NULL;

    // set size to minimum size of the two arrays
    size = sizeof(array1);

    if (sizeof(array2) < size)
        size = sizeof(array2);

    size = size / sizeof(int);

    while (choice != 5)
    {
        printf("\n\nWhich operation do you want to perform? \n");
        printf("1.Add \n");
        printf("2.Subtract \n");
        printf("3.Multiply \n");
        printf("4.Divide \n");
        printf("5.None ... \n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);

        if (choice == 5) break;
        if (choice < 1 || choice > 5) continue;

        int j = choice - 1;

        result = performOp(array1, array2, size, fpArr[j]);

        printf("\n\nThe Results are ...\n");
        display(result, size);

        if (result != NULL)
            free(result);

    }

    /* double pointer */

    int num = 123;

    //A normal pointer singlePointer
    int* singlePointer = NULL;

    //This pointer doublePointer is a double pointer
    int** doublePointer = NULL;

    //Assigning the address of variable num to the single pointer
    singlePointer = &num;

    //Assigning the address of pointer singlePointer to the doublePointer
    doublePointer = &singlePointer;


    /* Possible ways to find value of variable num*/
    printf("\n Value of num is: %d", num);
    printf("\n Value of num using singlePointer is: %d", *singlePointer);
    printf("\n Value of num using doublePointer is: %d", **doublePointer);

    /*Possible ways to find address of num*/
    printf("\n Address of num is: %p", &num);
    printf("\n Address of num using singlePointer is: %p", singlePointer);
    printf("\n Address of num using doublePointer is: %p", *doublePointer);

    /*Find value of pointer*/
    printf("\n Value of Pointer singlePointer is: %p", singlePointer);
    printf("\n Value of Pointer singlePointer using doublePointer is: %p", *doublePointer);

    /*Ways to find address of pointer*/
    printf("\n Address of Pointer singlePointer is:%p", &singlePointer);
    printf("\n Address of Pointer singlePointer using doublePointer is:%p", doublePointer);

    /*Double pointer value and address*/
    printf("\n Value of Pointer doublePointer is:%p", doublePointer);
    printf("\n Address of Pointer doublePointer is:%p", &doublePointer);

    /* simple pointer examples */

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
