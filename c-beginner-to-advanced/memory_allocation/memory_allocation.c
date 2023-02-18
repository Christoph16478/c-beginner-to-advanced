#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* variant one */
    char prename[20];
    char lastname[20];
    int year;
    int month;
    int day;
    printf("Enter your Prename: ");
    scanf_s("%20s", prename);
    printf_s("Enter your Lastname: ");
    scanf_s("%20s", lastname);
    printf_s("Enter your Birthday (DD MM YYYY)\n");
    // with ampersand operator memory address of varaible canbe accessed
    // &day refers to memory address of int year above
    scanf_s("%2d %2d %4d", &day, &month, &year);
    printf("Name: %s %s, Birthday: %2d %2d %4d", prename, lastname, day, month, year);

    /* variant two */
    // executed with dynamic memory allocation
    // src: https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
    char* prename1;
    char* lastname1;
    // size of char is 1 byte, so 20 bytes are allocated
    // the pointer prename1 holds the first byte in the allocated memory
    // src: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
    prename1 = (char*)malloc(20 * sizeof(char));
    if (prename1 == NULL)
    {
        printf("Error allocating memory!");
        exit(1);
    }
    free(prename1);
    lastname1 = (char*)malloc(20 * sizeof(char));
    if (lastname1 == NULL)
    {
        printf("Error allocating memory!");
        exit(1);
    }
    free(lastname1);
    printf("\nEnter your Prename: ");
    scanf_s("%20s", prename1);
    printf("Enter your Lastname: ");
    scanf_s("%20s", lastname1);
    printf("Enter your Birthday (DD MM YYYY)\n");
    scanf_s("%2d %2d %4d", &day, &month, &year);
    printf("Name: %s %s, Birthday: %2d %2d %4d", prename1, lastname1, day, month, year);

    return 0;
}
