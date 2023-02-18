#include <stdio.h>
#include <stdlib.h>

// Macro definitions
#define IS_UPPER(x) (x >= 'A' && x <= 'Z')
// #define IS_LOWER(x) (x >= 'a' && x <= 'z)
#define IS_ALPHABET(x) (IS_LOWER(x) || IS_UPPER(x))
#define IS_VOWEL_LOWER(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
#define IS_VOWEL_UPPER(x) (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define IS_VOWEL(x) (IS_VOWEL_LOWER(x) || IS_VOWEL_UPPER(x))
#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_ALPHANUMERIC(x) (IS_ALPHABET(x) || IS_DIGIT(x))
#define IS_WHITE_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\n' || x == '\0')
#define IS_SPECIAL_CHARACTERS(x) (x >= 32 && x <= 127 && !IS_ALPHABET(x) && !IS_DIGIT(x) && !IS_WHITE_SPACE(x))
// Define macro to find square and cube
#define SQUARE(x) (x * x)
#define CUBE(x) (x * x * x)
#define SUM(x, y) (x + y)

int main()
{
    // 4. solution
    char ch;
    // Input a character from user
    printf("Enter any character: ");
    ch = getchar();
    if (IS_UPPER(ch))
    {
        printf("'%c' is uppercase\n", ch);
    }
    //else if (IS_LOWER(ch))
    //{
    //    printf("'%c' is lowercase\n", ch);
    //}
    else
    {
        printf("Entered character is not alphabet");
    }

    // 3. solution
    int num;
    // Input a number from user
    printf("Enter any number to find square and cube: ");
    scanf_s("%d", &num);
    // Calculate and print square
    printf("SQUARE(%d) = %d\n", num, SQUARE(num));
    // Calculate and print cube
    printf("CUBE(%d) = %d\n", num, CUBE(num));

    // 2. solution
    int num1, num2;
    // Input two numbers from user
    printf("Enter any two numbers: ");
    scanf_s("%d%d", &num1, &num2);
    // Calculate and print sum using macro
    printf("Sum(%d, %d) = %d\n", num1, num2, SUM(num1, num2));

    // 1. print values of predefined macros
    printf("__LINE__ = %d\n", __LINE__);
    printf("__FILE__ = %s\n", __FILE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    // printf("__STDC__ = %s\n", __STDC__); // Error: identifier __STDC__ is undefined

    return 0;
}
