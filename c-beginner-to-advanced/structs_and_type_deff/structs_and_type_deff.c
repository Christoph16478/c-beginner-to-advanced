#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include "structs_and_type_def_funcs.c"

//struct Vector
//{
//    float* data;
//    unsigned int length;
//};
//
//typedef struct Vector Vector;

//inline void printEvenOrOdd(int number);
//inline int getNumberFromUser();
//inline unsigned int factorial(unsigned int i);
//inline float mean(int number_a, int number_b);
//inline void binom(int* a, int* b, int* c);
//inline float meanArray(int array[], unsigned int length);
//inline int minArray(int array[], unsigned int length);
//inline int maxArray(int array[], unsigned int length);
////inline Vector* createVector(unsigned int length, float value);
//inline int** createMatrix(unsigned int rows, unsigned int cols, int value);
//inline int** transposeMatrix(int** matrix_input, unsigned int rows, unsigned int cols);
// inline Vector* createVector(unsigned int length, float value);
//inline float meanVector(Vector* vec);
//inline float minVector(Vector* vec);
//inline float maxVector(Vector* vec);

int main()
{
    //Vector v1 = { createVector(10, 1), 3 };

    //for (int i = 0; i < v1.length; i++)
    //{
    //    v1.data[i] = i;
    //}

    //int max_v1 = maxVector(&v1);
    //int min_v1 = minVector(&v1);
    //float mean_v1 = meanVector(&v1);

    //printf("%d\n", max_v1);
    //printf("%d\n", min_v1);
    //printf("%f\n", mean_v1);

    return 0;
}

// Definiton
//float meanVector(Vector* vec)
//{
//    float sum = 0.0f;
//
//    for (int i = 0; i < vec->length; i++)
//    {
//        sum += vec->data[i];
//    }
//
//    float mean = sum / vec->length;
//    return mean;
//}

// Definiton
//float minVector(Vector* vec)
//{
//    float min;
//
//    for (int i = 0; i < vec->length; i++)
//    {
//        if (i == 0)
//        {
//            min = vec->data[i];
//        }
//
//        if (vec->data[i] < min)
//        {
//            min = vec->data[i];
//        }
//    }
//
//    return min;
//}

// Definiton
//float maxVector(Vector* vec)
//{
//    float max;
//
//    for (int i = 0; i < vec->length; i++)
//    {
//        if (i == 0)
//        {
//            max = vec->data[i];
//        }
//
//        if (vec->data[i] > max)
//        {
//            max = vec->data[i];
//        }
//    }
//
//    return max;
//}

// Definiton
//Vector* createVector(unsigned int length, float value)
//{
//    Vector* vec = (Vector*)malloc(sizeof(Vector));
//    float* vec_data = (float*)malloc(length * sizeof(float));
//
//    for (int i = 0; i < length; i++)
//    {
//        vec_data[i] = value;
//    }
//
//    vec->data = vec_data;
//    vec->length = length;
//
//    return vec;
//}
