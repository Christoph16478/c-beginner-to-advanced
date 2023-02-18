#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    float* data;
    unsigned int length;
};

typedef struct Vector Vector;

inline Vector* createVector(unsigned int length, float value);

inline void deleteVector(Vector* vec);

inline Vector* addVectors(Vector* vec1, Vector* vec2);

inline Vector* subVectors(Vector* vec1, Vector* vec2);

inline double dotVectors(Vector* vec1, Vector* vec2);

inline Vector* multiplyScalarVector(double scalar, Vector* vec);

inline Vector* divideScalarVector(double scalar, Vector* vec);

inline void printVector(Vector* vec);

inline float meanVector(Vector* vec);

inline float minVector(Vector* vec);

inline float maxVector(Vector* vec);

inline int readInVectorData(Vector* vec, const char* path);

inline int writeOutVectorData(Vector* vec, const char* path);

#endif
