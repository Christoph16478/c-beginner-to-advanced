#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    /*
    calculate perimeter and area of a rectangle
        1) read values from the user
        2) compute the perimeter and area of the rectangle
        3) print results
    */

    float length;
    float width;

    printf("Please enter length: ");
    scanf_s("%f", &length);
    printf("Please enter width: ");
    scanf_s("%f", &width);

    float rectangle_perimeter = 2 * length + 2 * width;
    float rectangle_area = length * width;

    printf("the perimeter is: %f\n", rectangle_perimeter);
    printf("the area is: %f", rectangle_area);

    return 0;
}
