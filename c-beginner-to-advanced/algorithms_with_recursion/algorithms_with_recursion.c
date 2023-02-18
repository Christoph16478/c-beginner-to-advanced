#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* link;
};

inline int sum1(int n);
inline void print1(int n);
inline void print2(int n);
inline int series(int n);
inline long TailRecursiveFact(int n);
inline long TRfact(int n, int result);
inline struct node* createList(struct node* start);
inline void displayList(struct node* p);
inline void displayListR(struct node* p);
inline int countNodes(struct node* p);
inline int sumStruct(struct node* p);
inline int search(struct node* p, int x);
inline struct node* insertLast(struct node* p, int value);
inline struct node* delLast(struct node* p);
inline long int factorial(int n);
inline long int sum(int n);
inline int fib(int n);
inline int GCD(int a, int b);
inline float power(float x, int n);
inline void toBinary(int n);
inline int series1(int n);
inline void convertBase(int, int);
inline int sumDigits(long int n);
inline void hanoi(int n, char source, char temp, char dest);

int main()
{
	/* display numbers 1toN */
	int n;
	printf("Enter value of n : ");
	scanf_s("%d", &n);
	print1(n);	printf("\n");
	print2(n);	printf("\n");
	printf("Sum1 = %d\n", sum1(n));
	printf("\b\b = %d\n", series1(n));

	/* factorial tail recursive */
	int num;
	printf("Enter a number : ");
	scanf_s("%d", &num);
	if (num < 0)
		printf("No factorial for negative number\n");
	printf("Factorial of %d is %ld\n", num, TailRecursiveFact(num));

	/* linked list */
	struct node* start = NULL;
	int choice, x;
	start = createList(start);

	while (1)
	{
		printf("1.Display List\n");
		printf("2.Display List in reverse order\n");
		printf("3.Count nodes\n");
		printf("4.Sum of elements of the list\n");
		printf("5.Search for an element\n");
		printf("6.Insert at the end of the list\n");
		printf("7.Delete the last node of the list\n");
		printf("8.Quit\n");

		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 8)
			break;

		printf("\n");
		switch (choice)
		{
		case 1:
			displayList(start);
			printf("\n\n");
			break;
		case 2:
			displayListR(start);
			printf("\n\n");
			break;
		case 3:
			printf("Number of nodes=%d\n\n", countNodes(start));
			break;
		case 4:
			printf("Sum of elements = %d\n\n", sumStruct(start));
			break;
		case 5:
			printf("Enter the element to be searched : ");
			scanf_s("%d", &x);
			if (search(start, x) == 1)
				printf("%d present in list\n\n", x);
			else
				printf("%d not present in the list\n\n", x);
			break;
		case 6:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &x);
			start = insertLast(start, x);
			break;
		case 7:
			start = delLast(start);
			printf("Last node deleted......\n");
			break;
		default:
			printf("Wrong choice\n");
		}
	}

	/* factorial */
	// int n;
	printf("Enter a number greater than or equal to zero : ");
	scanf_s("%d", &n);
	printf("Factorial of %d is %ld\n", n, factorial(n));
	printf("Sum of numbers from 1 to %d is %ld\n", n, sum(n));

	/* fibonacci */
	int terms, i;

	printf("Enter number of terms : ");
	scanf_s("%d", &terms);

	for (i = 0; i <= terms; i++)
		printf("%d  ", fib(i));
	printf("\n");


	/* euclids algorithm */
	int a, b;
	printf("Enter values for a and b : ");
	scanf_s("%d%d", &a, &b);
	printf("GCD of %d and %d is %d\n", a, b, GCD(a, b));


	/* display sum of series */
	int l;
	printf("Enter number of terms : ");
	scanf_s("%d", &l);
	printf("\b\b = %d\n", series(3));

	/* exponention */
	float z;
	int y;
	printf("Enter values for x and n : ");
	scanf_s("%f %d", &z, &y);
	printf("%f^%d = %f\n", z, y, power(z, y));

	/* base conversion */
	int n2;
	printf("Enter a positive decimal number : ");
	scanf_s("%d", &n2);
	printf("Binary form : "); toBinary(n2);		printf("\n");
	printf("Binary form : "); convertBase(n2, 2);	printf("\n");
	printf("Octal form : "); convertBase(n2, 8);	printf("\n");
	printf("Hexadecimal form : "); convertBase(n2, 16);	printf("\n");

	/* sum of digits */
	long int n1;
	printf("Enter a number : ");
	scanf_s("%ld", &n1);
	printf("%d\n", sumDigits(n1));

	/* tower of hanoi */
	int w;
	printf("Enter the number of disks : ");
	scanf_s("%d", &w);
	hanoi(w, 'A', 'B', 'C');
}

int sum1(int n)
{
	if (n == 0)
		return 0;
	return n + sum(n - 1);
}

void print1(int n)
{
	if (n == 0)
		return;
	printf("%d ", n);
	print1(n - 1);
}

void print2(int n)
{
	if (n == 0)
		return;
	print2(n - 1);
	printf("%d ", n);
}

int series1(int n)
{
	int sum;
	if (n == 0)
		return 0;
	sum = (n + series(n - 1));
	printf("%d + ", n);
	return sum;
}

struct node* createList(struct node* start)
{
	int i, n, data;
	struct node* p, * temp;

	printf("Enter the number of nodes : ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf_s("%d", &data);

		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = NULL;

		if (start == NULL) /*If list is empty */
			start = temp;
		else /*Inserted at the end*/
		{
			p = start;
			while (p->link != NULL)
				p = p->link;
			p->link = temp;
		}
	}
	return start;
}

long TRfact(int n, int result)
{
	if (n == 0)
		return result;
	return TRfact(n - 1, n * result);
}

long TailRecursiveFact(int n)
{
	return TRfact(n, 1);
}

void displayList(struct node* p)
{
	if (p == NULL)
		return;
	printf("%d ", p->info);
	displayList(p->link);
}

void displayListR(struct node* p)
{
	if (p == NULL)
		return;
	displayListR(p->link);
	printf("%d ", p->info);
}

int countNodes(struct node* p)
{
	if (p == NULL)
		return 0;
	return 1 + countNodes(p->link);
}

int sumStruct(struct node* p)
{
	if (p == NULL)
		return 0;
	return p->info + sum(p->link);
}

int search(struct node* p, int x)
{
	if (p == NULL)
		return 0;
	if (p->info == x)
		return 1;
	return search(p->link, x);
}

struct node* insertLast(struct node* p, int x)
{
	struct node* temp;
	if (p == NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = x;
		temp->link = NULL;
		return temp;
	}
	p->link = insertLast(p->link, x);
	return p;
}

struct node* delLast(struct node* p)
{
	if (p->link == NULL)
	{
		free(p);
		return NULL;
	}
	p->link = delLast(p->link);
	return p;
}

long int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

long int sum(int n)
{
	if (n == 1)
		return 1;
	return n + sum(n - 1);
}

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int series(int n)
{
	int sum;
	if (n == 0)
		return 0;
	sum = (n + series(n - 1));
	printf("%d + ", n);
	return sum;
}

float power(float x, int n)
{
	if (n == 0)
		return 1;
	return x * power(x, n - 1);
}

//float power(float x, int n)
//{
//	if (n == 0)
//		return 1;
//	return x * power(x, n - 1);
//}

void toBinary(int n)
{
	if (n == 0)
		return;
	toBinary(n / 2);
	printf("%d", n % 2);
}

void convertBase(int n, int base)
{
	int remainder;

	if (n == 0)
		return;
	convertBase(n / base, base);

	remainder = n % base;
	if (remainder < 10)
		printf("%d", remainder);
	else
		printf("%c", remainder - 10 + 'A');
}

int sumDigits(long int n)
{
	if (n / 10 == 0)
		return n;
	return sumDigits(n / 10) + n % 10;
}

void hanoi(int n, char source, char temp, char dest)
{
	if (n == 1)
	{
		printf("Move Disk %d from %c-->%c\n", n, source, dest);
		return;
	}
	hanoi(n - 1, source, dest, temp);
	printf("Move Disk %d from %c-->%c\n", n, source, dest);
	hanoi(n - 1, temp, source, dest);
}