#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("==========\n");
    printf("ITERATIONS\n");
    printf("==========\n\n");

    printf("for loop\n");
    printf("--------\n");
    int num_iterations = 5;
    for (int i = 0; i < num_iterations; i++)
    {
        printf("%d\n", i);
    }
    printf("\n");
    for (int i = 0; i < num_iterations; i += 2)
    {
        printf("%d\n", i);
    }
    printf("\n");
    for (int i = num_iterations - 1; i >= 0; i--)
    {
        printf("%d\n", i);
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d, %d\n", i, j);
        }
    }
    printf("\n\n");

    printf("nested for loop\n");
    printf("---------------\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == 0)
                printf("<\t");
            else if (j == 5)
                printf(">\t");
            else if (i == 0)
                printf("  ^\t");
            else if (i == 5)
                printf("  v\t");
            else
                printf("(%d,%d)\t", i, j);
        }

        printf("\n\n");
    }

    printf("while1\n");
    printf("------\n");

    int i = 0;
    while (i < num_iterations)
    {
        printf("Hello World!\n");
        i++;
    }

    printf("while2\n");
    printf("------\n");

    while (1)
    {
        printf("Hello World!\n");
        i++;
        if (i >= num_iterations)
        {
            break;
        }
    }

    printf("do while\n");
    printf("--------\n");

    int goal = 13;
    int selection;

    printf("welcome to our guessing game!");
    printf("you have to guess the right number from the interval of [1, 20]\n");

    do
    {
        printf("\nPlease enter a number: ");
        scanf_s("%d", &selection);
        if (selection < 1 || selection > 20)
        {
            printf("You did not enter a valid number!\n");
            printf("You have %d guesses left!", num_iterations - (i + 1));
        }
        else if (selection == goal)
        {
            printf("You have won the game!\n");
        }
        else
        {
            printf("Not correct. Please try again!\n");
            printf("You have %d guesses left!", num_iterations - (i + 1));
        }

        i++;
    } while (i < num_iterations);

    printf("increment and decrement\n");
    printf("-----------------------\n");

    int a = 1;
    // Increment: a = a + 1 <=> a += 1 <=> a++
    // Decrement: a = a - 1 <=> a -= 1 <=> a--
    printf("%d\n", a);
    a++;
    // ++a,
    printf("%d\n", a);
    a--;
    // --a;
    printf("%d\n", a);

    printf("square\n");
    printf("-------\n");
    printf("square: read length of square\n");
    printf("check if input is valid\n");
    printf("if not, ask user again for correct number\n");
    printf("calculate perimeter of square\n");
    printf("enter values in consol\n");
    printf("u = 4 * a\n");
    printf("a = a**2\n");
    int is_valid_number = 0;
    float a_float;

    while (is_valid_number == 0)
    {
        printf("Please enter the value for a_float: ");
        scanf_s("%f", &a_float);

        if (a_float > 0.0)
        {
            is_valid_number = 1;
        }
        else
        {
            printf("you entered a_float not valid number!\n");
        }
    }

    float perimeter = 4 * a_float;
    float area = a_float * a_float;

    printf("perimeter %f, area %f", perimeter, area);
    printf("hello world!\n");

    return 0;
}
