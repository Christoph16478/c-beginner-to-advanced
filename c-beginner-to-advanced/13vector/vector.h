#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    float* data;
    unsigned int length;
};

typedef struct Vector Vector;

Vector* createVector(unsigned int length, float value);

void deleteVector(Vector* vec);

Vector* addVectors(Vector* vec1, Vector* vec2);

Vector* subVectors(Vector* vec1, Vector* vec2);

double dotVectors(Vector* vec1, Vector* vec2);

Vector* multiplyScalarVector(double scalar, Vector* vec);

Vector* divideScalarVector(double scalar, Vector* vec);

void printVector(Vector* vec);

float meanVector(Vector* vec);

float minVector(Vector* vec);

float maxVector(Vector* vec);

int readInVectorData(Vector* vec, const char* path);

int writeOutVectorData(Vector* vec, const char* path);

#endif
