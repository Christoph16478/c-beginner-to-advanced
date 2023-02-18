#include <stdio.h>
#define MAX 100

main()
{
	int a[MAX], i, j, n, temp, minIndex;

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ", i + 1);
		scanf_s("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
				minIndex = j;
		}
		if (i != minIndex)
		{
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}

	printf("Sorted array is : \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}






