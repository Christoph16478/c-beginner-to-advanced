#include <stdio.h>
#include <stdlib.h>
#include "pointers_in_arrays_func.h"

int** createMatrix(unsigned int rows, unsigned int cols, int value)
{
    int** matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = value;
        }
    }

    return matrix;
}

int** transposeMatrix(int** matrix_input, unsigned int rows, unsigned int cols)
{
    int** matrix_transpose = createMatrix(cols, rows, 0);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix_transpose[j][i] = matrix_input[i][j];
        }
    }

    return matrix_transpose;
}
