#include <stdio.h>
#include <stdlib.h>

// -5, -2, -1, 1, 2, 3, 4

// -2, -1, 1, -5, 2, 3, 4
void bubblesort(int* array, int length)
{
    int i, j, temp;

    for (i = 1; i < length; i++)
    {
        for (j = 0; j < length - i; j++)
        {

            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int comp(const void* elem1, const void* elem2)
{
    int l = *((int*)elem1);
    int r = *((int*)elem2);

    if (l > r) return 1;
    if (r > l) return -1;
    else return 0;
}

int main()
{
    // Main 1
    if (argc == 1)
    {
        printf("You have to enter 3 args!\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File %s does not exist!\n", argv[1]);
        return 1;
    }

    int length = atoi(argv[2]);
    int* data = (int*)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d", &data[i]);
        printf("%d\n", data[i]);
    }

    fclose(fp);
    printf("\n");
    fp = fopen(argv[1], "w");

    qsort(data, length, sizeof(int), comp);

    for (int i = 0; i < length; i++)
    {
        fprintf(fp, "%d\n", data[i]);
        printf("%d\n", data[i]);
    }

    // Main 2
    int* data = (int*)malloc(4 * sizeof(int));
    data[0] = -2;
    data[1] = 3;
    data[2] = -1;
    data[3] = 12;

    qsort(data, 4, sizeof(int), comp);

    for (int i = 0; i < 4; i++)
    {
        printf("Data[%d] = %d\n", i, data[i]);
    }
}
