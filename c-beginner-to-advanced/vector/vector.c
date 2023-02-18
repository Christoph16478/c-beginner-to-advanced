#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    Vector* v1 = createVector(3, 1.0);
    printf("v1 = \n");
    printVector(v1);

    Vector* v2 = createVector(3, 2.0);
    printf("v2 = \n");
    printVector(v2);

    Vector* v3 = addVectors(v1, v2);
    printf("v3 = \n");
    printVector(v3);

    Vector* v4 = subVectors(v3, v2);
    printf("v4 = \n");
    printVector(v4);

    // = 1 * 2 + 1 * 2 + 1 * 2 = 3 * 2 = 6
    double vector_dot = dotVectors(v1, v2);
    printf("Dot = %f\n", vector_dot);

    Vector* v5 = multiplyScalarVector(2.0, v1);
    printf("v5 = \n");
    printVector(v5);

    Vector* v6 = divideScalarVector(2.0, v5);
    printf("v6 = \n");
    printVector(v6);

    writeOutVectorData(v6, "data.txt");

    deleteVector(v1);
    deleteVector(v2);
    deleteVector(v3);
    deleteVector(v4);
    deleteVector(v5);
    deleteVector(v6);

    return 0;
}


// Definiton
Vector* createVector(unsigned int length, float value)
{
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    float* vec_data = (float*)malloc(length * sizeof(float));

    for (int i = 0; i < length; i++)
    {
        vec_data[i] = value;
    }

    vec->data = vec_data;
    vec->length = length;

    return vec;
}

// Definiton
void deleteVector(Vector* vec)
{
    free(vec->data);
    free(vec);
}

// Definiton
Vector* addVectors(Vector* vec1, Vector* vec2)
{
    Vector* vec_result = createVector(vec1->length, 0.0);

    for (int i = 0; i < vec1->length; i++)
    {
        vec_result->data[i] = vec1->data[i] + vec2->data[i];
    }

    return vec_result;
}

// Definiton
Vector* subVectors(Vector* vec1, Vector* vec2)
{
    Vector* vec_result = createVector(vec1->length, 0.0);

    for (int i = 0; i < vec1->length; i++)
    {
        vec_result->data[i] = vec1->data[i] - vec2->data[i];
    }

    return vec_result;
}

// Definiton
double dotVectors(Vector* vec1, Vector* vec2)
{
    double result = 0.0;

    for (int i = 0; i < vec1->length; i++)
    {
        result += vec1->data[i] * vec2->data[i];
    }

    return result;
}

// Definiton
Vector* multiplyScalarVector(double scalar, Vector* vec)
{
    Vector* vec_result = createVector(vec->length, 0.0);

    for (int i = 0; i < vec->length; i++)
    {
        vec_result->data[i] = vec->data[i] * scalar;
    }

    return vec_result;
}

// Definiton
Vector* divideScalarVector(double scalar, Vector* vec)
{
    Vector* vec_result = createVector(vec->length, 0.0);

    for (int i = 0; i < vec->length; i++)
    {
        vec_result->data[i] = vec->data[i] / scalar;
    }

    return vec_result;
}

// Definiton
void printVector(Vector* vec)
{
    for (int i = 0; i < vec->length; i++)
    {
        printf("%f\n", vec->data[i]);
    }

    printf("\n");
}

// Definiton
float meanVector(Vector* vec)
{
    float sum = 0.0f;

    for (int i = 0; i < vec->length; i++)
    {
        sum += vec->data[i];
    }

    float mean = sum / vec->length;
    return mean;
}

// Definiton
float minVector(Vector* vec)
{
    float min;

    for (int i = 0; i < vec->length; i++)
    {
        if (i == 0)
        {
            min = vec->data[i];
        }

        if (vec->data[i] < min)
        {
            min = vec->data[i];
        }
    }

    return min;
}

// Definiton
float maxVector(Vector* vec)
{
    float max;

    for (int i = 0; i < vec->length; i++)
    {
        if (i == 0)
        {
            max = vec->data[i];
        }

        if (vec->data[i] > max)
        {
            max = vec->data[i];
        }
    }

    return max;
}

// Definiton
int readInVectorData(Vector* vec, const char* path)
{
    FILE* fp = fopen_s(vec, path, "r");

    if (fp == NULL)
    {
        return 1;
    }

    for (int i = 0; i < vec->length; i++)
    {
        fscanf_s(fp, "%f", &vec->data[i]);
    }

    fclose(fp);
    return 0;
}

// Definiton
int writeOutVectorData(Vector* vec, const char* path)
{
    FILE* fp = fopen_s(vec, path, "w");

    if (fp == NULL)
    {
        return 1;
    }

    for (int i = 0; i < vec->length; i++)
    {
        if (i < vec->length - 1)
            fprintf(fp, "%f\n", vec->data[i]);
        else
            fprintf(fp, "%f", vec->data[i]);
    }

    fclose(fp);
    return 0;
}
