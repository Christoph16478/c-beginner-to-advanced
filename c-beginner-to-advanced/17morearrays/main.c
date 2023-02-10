#include <stdio.h>
#include <stdlib.h>

struct myArray
{
	int len;
	int array[];
};

int main()
{
	// solution 3
	double complex z1 = I * I;     // imaginary unit squared
	printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

	double complex z2 = pow(I, 2); // imaginary unit squared
	printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

	double PI = acos(-1);
	double complex z3 = exp(I * PI); // Euler's formula
	printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

	double complex z4 = 1 + 2 * I, z5 = 1 - 2 * I; // conjugates
	printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4 * z5), cimag(z4 * z5));

	// solution 2
	struct myArray* m = NULL;
	int arraySize = 0;

	printf("Enter the size of the flexible array\n");
	scanf("%d", &arraySize);

	size_t size = sizeof(struct myArray);
	m = malloc(size + (sizeof(int) * arraySize));

	m->len = arraySize;
	m->array[0] = 55;
	m->array[1] = 199;

	printf("array is: %d:%d\n", m->array[0], m->array[1]);


	// solution 1
	int i, sum = 0, size = 0;
	printf("Enter size of the array: ");
	scanf("%d", &size);

	int arr[size];

	printf("Enter %d elements in the array: ", size);

	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < size; i++) {
		sum = sum + arr[i];
	}

	printf(�\nSum of all elements of array = % d�, sum);
	return 0;
}
