#include <stdio.h>
#include <stdlib.h>
#include "incrementation_funcs.c"

int main()
{
    int i = 0;
    // post-increment
    printf("%d\n", i++);
    // pre-increment
    printf("%d\n", ++i);

    int j = 0;
    // post-increment
    my_function(j++);
    // pre-increment
    my_function(++j);

    // post-increment
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", i);
    }
    // pre-increment
    for (int i = 0; i < 3; ++i)
    {
        printf("%d\n", i);
    }

    return 0;
}
