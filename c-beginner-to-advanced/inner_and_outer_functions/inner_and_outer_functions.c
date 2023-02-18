#include <stdio.h>
#include "inner_and_outer_fs.c"

int main()
{
    int a = 1;
    int b = 2;
    for (int i = 0; i < 3; i++)
    {
        a = my_outer_computation(a, b);
    }

    return 0;
}
