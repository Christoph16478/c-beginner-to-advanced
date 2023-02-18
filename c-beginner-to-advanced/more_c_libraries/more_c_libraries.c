#include <stdio.h>
#include <stdlib.h>

#define NUM 40

void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void* p1, const void* p2);

int main()
{
    // solution 4
    //time_t now;
    //time(&now);
    //struct tm beg_month;
    //beg_month = *localtime(&now);
    //beg_month.tm_hour = 0;
    //beg_month.tm_min = 0;
    //beg_month.tm_sec = 0;
    //beg_month.tm_mday = 1;
    //double seconds = difftime(now, mktime(&beg_month));
    //printf("\n %.f seconds passed since the beginning of the month.\n\n", seconds);
    // solution 3
    time_t cur_time;
    char* cur_t_string;
    cur_time = time(NULL);

    if (cur_time == ((time_t)-1))
    {
        (void)fprintf(stderr, "Failure to get the current time.\n");
        exit(EXIT_FAILURE);
    }
    cur_t_string = ctime(&cur_time); //convert to local time format
    if (cur_t_string == NULL)
    {
        (void)fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
    (void)printf("\n The Current time is : %s \n", cur_t_string);
    exit(EXIT_SUCCESS);
    // solution 2
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
    // solution 1
    int i = 0;
    char str = '\0';
    srand(time(NULL));
    // printf("%d\n", N);
    //for (i = 1; i <= N; i++)
    //{
    //    printf("%0.4lf\n", (rand() % 2001 - 1000) / 2.e3);
    //}
    //return 0;
}

void fillarray(double ar[], int n) {
    int index;

    for (index = 0; index < n; index++)
        ar[index] = (double)rand() / ((double)rand() + 0.1);
}

void showarray(const double ar[], int n) {
    int index;

    for (index = 0; index < n; index++) {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar('\n');
    }

    if (index % 6 != 0)
        putchar('\n');
}

/* sort by increasing value */
int mycomp(const void* p1, const void* p2) {

    /* need to use pointers to double to access values   */
    const double* a1 = (const double*)p1;
    const double* a2 = (const double*)p2;

    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
