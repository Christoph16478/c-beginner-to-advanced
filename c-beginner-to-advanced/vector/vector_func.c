#include <stdio.h>
#include <stdlib.h>
#include "vector_func.h"
#define _CRT_SECURE_NO_WARNINGS

// Definition
void printEvenOrOdd(int number)
{
    if ((number % 2) == 0)
    {
        printf("Even!\n");
    }
    else
    {
        printf("Odd!\n");
    }
}

// Definition
int getNumberFromUser()
{
    int number_from_user; //0x00: 12

    printf("Pls enter a interger number!\n");
    scanf_s("%d", &number_from_user);

    return number_from_user; // return 12;
}

// Definition
unsigned int factorial(unsigned int i)
{
    if (i <= 1)
    {
        return 1;
    }

    return i * factorial(i - 1);
}
