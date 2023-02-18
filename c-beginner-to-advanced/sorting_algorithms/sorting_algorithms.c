#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

static struct node
{
	struct node* lchild;
	int info;
	struct node* rchild;
};

struct node* stack[MAX];
int top;
inline void initializeStack();
inline void push(struct node* item);
inline struct node* pop();
inline int empty();

inline struct node* getnode(int x);
inline struct node* insertNode(struct node* root, int x);
inline void inorder(struct node* ptr, int a[]);
inline struct node* Destroy(struct node* ptr);

static struct node1
{
	int info;
	struct node1* link;
}*start = NULL;

inline void radixSort();
inline int digitsInLargest();
inline int digit(int number, int k);

static struct date
{
	int day;
	int month;
	int year;
};

static struct student
{
	char name[20];
	struct date dob;
	int grade;
};

inline void merge(int a1[], int a2[], int temp[], int n1, int n2);
inline void sortName(struct student stu[], int n);
inline void sortDob(struct student stu[], int n);
inline void sortGrade(struct student stu[], int n);
inline int dateCmp(struct date date1, struct date date2);

int main()
{
	int a[MAX], i, x, j, swaps, choice;
	/* merging */
	int n;
	int a1[MAX], a2[MAX], temp[2 * MAX], n1, n2;
	printf("Enter the number of elements in first array : ");
	scanf_s("%d", &n1);
	printf("Enter elements in sorted order :\n");
	for (i = 0; i < n1; i++)
	{
		printf("Enter element %d : ", i + 1);
		scanf_s("%d", &a1[i]);
	}
	printf("Enter the number of elements in second array : ");
	scanf_s("%d", &n2);
	printf("Enter elements in sorted order :\n");
	for (i = 0; i < n2; i++)
	{
		printf("Enter element %d : ", i + 1);
		scanf_s("%d", &a2[i]);
	}
	merge(a1, a2, temp, n1, n2);
	printf("Merged Array is : ");
	for (i = 0; i < n1 + n2; i++)
		printf("%d ", temp[i]);
	printf("\n");

	/* binary tree sort */
	struct node* root = NULL;
	// int a[MAX];

	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ", i + 1);
		scanf_s("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
		root = insertNode(root, a[i]);

	inorder(root, a);

	printf("\nSorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	root = Destroy(root);


	/* radix sort */
	struct node1* temp1, * p;
	// int i, n, 
	int item;
	

	printf("Enter number of elements in the list : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ", i + 1);
		scanf_s("%d", &item);

		/*Inserting elements in linked list*/
		temp1 = (struct node1*)malloc(sizeof(struct node1));
		temp1->info = item;
		temp1->link = NULL;

		if (start == NULL) /*Inserting first element */
			start = temp;
		else
		{
			p = start;
			while (p->link != NULL)
				p = p->link;
			p->link = temp;
		}
	}

	radixSort();

	printf("Sorted list is :\n");

	p = start;
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");

	/* sorting records */
	struct student stu[] = {
							{"Sam", {12,1,1993}, 2},
							{"Pam", {24,1,1993}, 3},
							{"Adam",{14,3,1992}, 4},
							{"Tom", {23,1,1994} ,4},
							{"Chris", {2,1,1992}, 3},
							{"John", {23,2,1993}, 2},
	};

	while (1)
	{
		printf("1.Sort by name alphabetically\n");
		printf("2.Sort by date of birth, in descending order\n");
		printf("3.Sort by grade in ascending order\n");
		printf("4.Exit\n");
		printf("Enter your choice :");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			sortName(stu, n);
			break;
		case 2:
			sortDob(stu, n);
			break;
		case 3:
			sortGrade(stu, n);
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice\n");
		}

		for (i = 0; i < n; i++)
		{
			printf("%s\t\t", stu[i].name);
			printf("%d/%d/%d\t\t", stu[i].dob.day, stu[i].dob.month, stu[i].dob.year);
			printf("%d\n", stu[i].grade);
		}
		printf("\n");
	}
}/*End of main()*/

void merge(int a1[], int a2[], int temp[], int n1, int n2)
{
	int i = 0, j = 0, k = 0;

	while ((i <= n1 - 1) && (j <= n2 - 1))
	{
		if (a1[i] < a2[j])
			temp[k++] = a1[i++];
		else
			temp[k++] = a2[j++];
	}

	/*copy remaining elements of a1, array a2 finished */
	while (i <= n1 - 1)
		temp[k++] = a1[i++];

	/*copy remaining elements of a2, array a1 finished */
	while (j <= n2 - 1)
		temp[k++] = a2[j++];
}

struct node* getnode(int x)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

struct node* insertNode(struct node* root, int x)
{
	struct node* temp, * par, * p;

	p = root;
	par = NULL;

	while (p != NULL)
	{
		par = p;
		if (x < p->info)
			p = p->lchild;
		else
			p = p->rchild;
	}

	temp = getnode(x);

	if (par == NULL)
		root = temp;
	else if (x < par->info)
		par->lchild = temp;
	else
		par->rchild = temp;

	return root;
}

void inorder(struct node* root, int a[])
{
	struct node* p;
	int i;

	if (root == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	initializeStack();
	p = root;
	i = 0;
	while (1)
	{
		/*Move on leftmost path rooted at p,pushing all the nodes in the path*/
		while (p->lchild != NULL) /*Stop when we reach leftmost node*/
		{
			push(p);
			p = p->lchild;
		}

		while (p->rchild == NULL) /*visit and pop nodes till a node with right subtree is popped*/
		{
			a[i++] = p->info; /*Visit p*/
			if (empty())  /*If stack becomes empty traversal is finished*/
				return;
			p = pop();
		}
		/*Now p points to node that has a right subtree*/
		a[i++] = p->info; /*Visit p*/
		p = p->rchild;  /*Move to right subtree of p*/
	}
	printf("\n");
}

struct node* Destroy(struct node* ptr)
{
	if (ptr != NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return NULL;
}

/*Functions for implementation of stack*/
void initializeStack()
{
	top = -1;
}

void push(struct node* item)
{
	if (top == (MAX - 1))
	{
		printf("Stack Overflow\n");
		return;
	}
	stack[++top] = item;
}

struct node* pop()
{
	struct node* item;
	if (top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack[top--];
	return item;
}

int empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void radixSort()
{
	int i, k, dig, leastSigPos, mostSigPos;
	struct node1* p, * rear[10], * front[10];

	leastSigPos = 1;
	mostSigPos = digitsInLargest();

	for (k = leastSigPos; k <= mostSigPos; k++)
	{
		/*Making all the queues empty at the beginning of each pass*/
		for (i = 0; i <= 9; i++)
		{
			rear[i] = NULL;
			front[i] = NULL;
		}

		for (p = start; p != NULL; p = p->link)
		{
			/*Find kth digit from right in the number*/
			dig = digit(p->info, k);

			/*Insert the node in Queue(dig) */
			if (front[dig] == NULL)
				front[dig] = p;
			else
				rear[dig]->link = p;
			rear[dig] = p;
		}

		/*Join all queues to form new linked list*/
		i = 0;
		while (front[i] == NULL)  /*Finding first non empty queue*/
			i++;
		start = front[i];
		while (i <= 8)
		{
			if (rear[i + 1] != NULL) /*if next queue (i+1)th  is not empty*/
				rear[i]->link = front[i + 1]; /*join end of ith queue to start of (i+1)th queue*/
			else
				rear[i + 1] = rear[i]; /*continue with rear[i]*/
			i++;
		}
		rear[9]->link = NULL;
	}/*End of for*/
}/*End of radixSort*/

/*Returns number of digits in the largest element of the list */
int digitsInLargest()
{
	struct node1* p = start;
	int large = 0, ndigits = 0;

	/*Find largest element*/
	while (p != NULL)
	{
		if (p->info > large)
			large = p->info;
		p = p->link;
	}
	/*Find number of digits in largest element*/
	while (large != 0)
	{
		ndigits++;
		large /= 10;
	}
	return ndigits;
}

/*Returns kth digit from right in n*/
int digit(int n, int k)
{
	int d, i;
	for (i = 1; i <= k; i++)
	{
		d = n % 10;
		n /= 10;
	}
	return d;
}

void sortName(struct student stu[], int n)
{
	struct student temp;
	int x, j, swaps;

	for (x = n - 2; x >= 0; x--)
	{
		swaps = 0;
		for (j = 0; j <= x; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name) > 0)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				swaps++;
			}
		}
		if (swaps == 0)
			break;
	}
}/*End of sortName()*/

void sortDob(struct student stu[], int n)
{
	struct student temp;
	int x, j, swaps;

	for (x = n - 2; x >= 0; x--)
	{
		swaps = 0;
		for (j = 0; j <= x; j++)
		{
			if (dateCmp(stu[j].dob, stu[j + 1].dob) > 0)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				swaps++;
			}
		}
		if (swaps == 0)
			break;
	}
}/*End of sortDob()*/


void sortGrade(struct student stu[], int n)
{
	struct student temp;
	int x, j, swaps;

	for (x = n - 2; x >= 0; x--)
	{
		swaps = 0;
		for (j = 0; j <= x; j++)
		{
			if (stu[j].grade > stu[j + 1].grade)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				swaps++;
			}
		}
		if (swaps == 0)
			break;
	}
}/*End of sortGrade()*/

/*Returns 1 if date1 < date2, returns -1 if date1 > date2, return 0 if equal*/
int dateCmp(struct date date1, struct date date2)
{
	if (date1.year < date2.year)
		return 1;
	if (date1.year > date2.year)
		return -1;
	if (date1.month < date2.month)
		return 1;
	if (date1.month > date2.month)
		return -1;
	if (date1.day < date2.day)
		return 1;
	if (date1.day > date2.day)
		return -1;
	return 0;
}/*End of dateCmp()*/
