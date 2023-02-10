#include <stdio.h>
#include <stdlib.h>

#define cola 0
#define icetea 1
#define water 2
#define coffee 3
#define PI 3.14159

int main(int argc, char** argv)
{
    printf("=====\n");
    printf("LOGIC\n");
    printf("=====\n\n");

    printf("comparison intro\n");
    printf("----------------\n");

    int a = 2;
    int b = 6;

    _Bool comparison;

    comparison = a > b;
    printf("a > b = %d\n", comparison);

    comparison = a < b;
    printf("a < b = %d\n", comparison);

    comparison = a == b;
    printf("a == b = %d\n", comparison);

    comparison = a != b;
    printf("a != b = %d\n", comparison);

    comparison = a >= b;
    printf("a >= b = %d\n", comparison);

    comparison = a <= b;
    printf("a <= b = %d\n\n", comparison);

    printf("if-statement\n");
    printf("------------\n");
    int age_jan = 27;
    printf("Jan is %d years old\n", &age_jan);
    if ((age_jan % 2) == 0)
    {
        printf("Jan's age is even\n");
    }
    else
    {
        printf("Jan's age is odd\n\n");
    }

    printf("comparison example\n");
    printf("------------------\n");

    int age_marc = 26;
    int age_sarah = 30;

    // &&: Conjunction, logical AND operator
    // ||: Disjunction, logical OR operator
    // !: Negation, logical NOT operator5


    if ((age_jan < age_marc) && (age_jan < age_sarah))
    {
        printf("Jan is the youngest!\n");
    }
    else if ((age_marc < age_jan) && (age_marc < age_sarah))
    {
        printf("Marc is the youngest!\n");
    }
    else if ((age_sarah < age_marc) && (age_sarah < age_jan))
    {
        printf("Sarah is the youngest!");
    }
    else
    {
        printf("At least two persons have the same age!");
    }

    if (age_jan < age_marc)
    {
        printf("Jan is younger than Marc!\n");
    }
    else if (age_jan > age_marc)
    {
        printf("Jan is older than Marc!\n");
    }
    else
    {
        printf("Jan and Marc have the same age!");
    }
    printf("\n\n");

    printf("circle\n");
    printf("------\n");

    float radius;
    printf("enter the radius: ");

    scanf_s("%f", &radius);
    if (radius < 0.0)
    {
        printf("negative number, please re-run program!");
    }
    else
    {
        float perimeter = 2 * radius * PI;
        float area = radius * radius * PI;
        printf("The perimeter is %f and the area is %f\n\n", perimeter, area);
    }

    printf("modulo\n");
    printf("------\n");
    printf("%d\n", a);
    printf("%d\n", b);

    int division = b / a;
    printf("b / a = %d\n", division);
    printf("%d / %d = %d\n", b, a, division);

    int remainder = b % a;
    printf("b %% a = %d\n", remainder);
    printf("%d %% %d = %d\n", b, a, remainder);

    return 0;
}
