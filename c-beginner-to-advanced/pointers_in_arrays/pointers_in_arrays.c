#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "pointers_in_arrays_func.c"

int main()
{
    /* memory allocation in matrix */

    // create matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("M^T[%d][%d] = %d\n", i, j, M_transpose[i][j]);
        }
    }
    // free the memory for M and M_transpose
    for (int i = 0; i < rows; i++)
    {
        free(M[i]);
        M[i] = NULL;
        free(M_transpose[i]);
        M_transpose[i] = NULL;
    }
    free(M);
    M = NULL;
    free(M_transpose);
    M_transpose = NULL;

    /* memory alocation in array */

    int length = 4;
    int* arr = (int*)calloc(length, length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        arr[i] = i;
        printf("%d\n", arr[i]);
    }
    // free the memory of arr
    free(arr);
    arr = NULL;
    if (arr != NULL)
    {
        printf("%x\n", arr);
    }
    else
    {
        printf("NULL");
    }

    return 0;
}
