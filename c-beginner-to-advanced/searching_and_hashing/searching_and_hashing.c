#include <stdio.h>
#include <stdlib.h>
// #define SIZE 100
#define SIZE 50
#define TSIZE 7

static struct student
{
	int studentId;
	char studentName[20];
};

static struct Node
{
	struct student info;
	struct Node* link;
};

inline void insert(struct student emprec, struct Node* table[]);
inline int search(int key, struct Node* table[]);
inline void del(int key, struct Node* table[]);
inline void displayTable(struct Node* table[]);
inline int hash(int key);
inline static int Search(int a[], int n, int searchValue);

int main()
{
	int i, n, searchValue, a[SIZE], index;

	struct Node* table[TSIZE];
	struct student rec;
	int key, choice;

	/* recursive binary search */

	// int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	printf("Enter the elements in sorted order : \n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	printf("Enter the item to be searched : ");
	scanf_s("%d", &searchValue);

	index = Search(a, n, searchValue);

	if (index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);

	/* linear probing */

	printf("1. Insert a record\n");
	printf("2. Search a record\n");
	printf("3. Delete a record\n");
	printf("4. Display table\n");
	printf("5. Exit\n");

	printf("Enter your choice\n");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("Enter studentId  : ");
		scanf_s("%d", &rec.studentId);
		printf("Enter student name : ");
		scanf_s("%s", rec.studentName);
		insert(rec, table);
		break;
	case 2:
		printf("Enter a key to be searched : ");
		scanf_s("%d", &key);
		i = search(key, table);
		if (i == -1)
			printf("Key not found\n");
		else
		{
			printf("Key found at index %d\n", i);
			// printf("%d %s", table[i].info.studentId, table[i].info.studentName);
		}
		break;
	case 3:
		printf("Enter a key to be deleted\n");
		scanf_s("%d", &key);
		del(key, table);
		break;
	case 4:
		displayTable(table);
		break;
	case 5:
		exit(1);
	}

	/* separate chaining */

	for (i = 0; i <= TSIZE - 1; i++)
		table[i] = NULL;

	while (1)
	{
		printf("1.Insert a record\n");
		printf("2.Search a record\n");
		printf("3.Delete a record\n");
		printf("4.Display table\n");
		printf("5.Exit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter studentId  : ");
			scanf_s("%d", &rec.studentId);
			printf("Enter student name : ");
			scanf_s("%s", rec.studentName);
			insert(rec, table);
			break;
		case 2:
			printf("Enter a key to be searched : ");
			scanf_s("%d", &key);
			i = search(key, table);
			if (i == -1)
				printf("Key not found\n");
			else
				printf("Key found in chain %d\n", i);
			break;
		case 3:
			printf("Enter a key to be deleted\n");
			scanf_s("%d", &key);
			del(key, table);
			break;
		case 4:
			displayTable(table);
			break;
		case 5:
			exit(1);
		}
	}

	/* sequential search */

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	printf("Enter the elements : \n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	printf("Enter the value to be searched : ");
	scanf_s("%d", &searchValue);

	index = Search(a, n, searchValue);

	if (index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);

	/* sequential search sentinel */

	// int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	printf("Enter the elements : \n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	printf("Enter the value to be searched : ");
	scanf_s("%d", &searchValue);

	index = Search(a, n, searchValue);

	if (index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);

	/* sequential search sorted array */

	// int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	printf("Enter the elements(in sorted order) : \n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	printf("Enter the value to be searched : ");
	scanf_s("%d", &searchValue);

	index = Search(a, n, searchValue);

	if (index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);

	/* binary search */

	// int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	printf("Enter the elements (in sorted order) : \n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	printf("Enter the value to be searched : ");
	scanf_s("%d", &searchValue);

	index = Search(a, n, searchValue);

	if (index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);
}

int hash(int key)
{
	return (key % TSIZE);
}

void insert(struct student rec, struct Node* table[])
{
	int h, key;
	struct Node* temp;

	key = rec.studentId;

	if (search(key, table) != -1)
	{
		printf("Duplicate key\n");
		return;
	}

	h = hash(key);

	/*Insert in the beginning of list h*/
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->info = rec;
	temp->link = table[h];
	table[h] = temp;
}

void displayTable(struct Node* table[])
{
	int i;
	struct Node* p;

	for (i = 0; i < TSIZE; i++)
	{
		printf("\n[%d]  ", i);

		if (table[i] != NULL)
		{
			p = table[i];
			while (p != NULL)
			{
				printf("%d %s\t", p->info.studentId, p->info.studentName);
				p = p->link;
			}
		}
	}
	printf("\n");
}

int search(int key, struct Node* table[])
{
	int h = hash(key);
	struct Node* p = table[h];

	while (p != NULL)
	{
		if (p->info.studentId == key)
		{
			printf("%d %s \n", p->info.studentId, p->info.studentName);
			return h;
		}
		p = p->link;

	}
	return -1;
}

void del(int key, struct Node* table[])
{
	int h;
	struct Node* temp, * p;
	h = hash(key);

	if (table[h] == NULL)
	{
		printf("Key %d not found\n", key);
		return;
	}
	if (table[h]->info.studentId == key)
	{
		temp = table[h];
		table[h] = table[h]->link;
		free(temp);
		return;
	}
	p = table[h];
	while (p->link != NULL)
	{
		if (p->link->info.studentId == key)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return;
		}
		p = p->link;
	}
	printf("Key %d not found\n", key);
}

int Search(int a[], int n, int searchValue)
{
	int first = 0, last = n - 1, mid;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (searchValue > a[mid])
			first = mid + 1;	/*Search in right half */
		else if (searchValue < a[mid])
			last = mid - 1;	/*Search in left half */
		else
			return mid;
	}
	return -1;
}