#include <stdio.h>
#include <stdlib.h>

int findGCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            return findGCD(a - b, b);
        else
            return findGCD(a, b - a);
    }
    return a;
}

int sumOfRange(int n1)
{
    int result = 0;
    if (n1 == 1)
    {
        return 1;
    }
    else
    {
        result = n1 + sumOfRange(n1 - 1);
    }
    return result;
}

char* reverse(char* str)
{
    static int i = 0;
    static char rev[100];
    if (*str)
    {
        reverse(str + 1);
        rev[i++] = *str;
    }
    return rev;
}

int main()
{
    // solution 1
    char str[100];
    char* rev = NULL;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("The original string is: %s\n", str);
    rev = reverse(str);
    printf("The reversed string is: %s\n", rev);
    // solution 2
    int num1 = 0, num2 = 0, gcd = 0;
    printf("\n\n Recursion : Find GCD of two numbers :\n");
    printf("------------------------------------------\n");
    printf(" Input 1st number: ");
    scanf("%d", &num1);
    printf(" Input 2nd number: ");
    scanf("%d", &num2);
    gcd = findGCD(num1, num2);
    printf("\n The GCD of %d and %d is: %d\n\n", num1, num2, gcd);
    // solution 3
    int n1 = 0;
    int sum = 0;
    printf("\n\n Recursion : calculate the sum of numbers from 1 to n :\n");
    printf("-----------------------------------------------------------\n");
    printf(" Input the last number of the range starting from 1 : ");
    scanf("%d", &n1);
    sum = sumOfRange(n1);
    printf("\n The sum of numbers from 1 to %d : %d\n\n", n1, sum);
    return (0);
}
