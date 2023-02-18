#include <stdio.h>
#include <stdlib.h>
#define LARGE_VALUE 99999

static struct node
{
	struct node* lchild;
	char info;
	struct node* rchild;
};

inline void insert(int value, int a[], int* pn);
inline int deleteRoot(int a[], int* pn);
inline void restoreUp(int a[], int loc);
inline void restoreDown(int a[], int i, int size);
inline void display(int a[], int n);

inline struct node* getnode(char x);
inline void display(struct node* p, int level);
inline void preorder(struct node* p);
inline void inorder(struct node* p);
inline void postorder(struct node* p);
inline void levelOrder(struct node* root);
inline int height(struct node* p);
inline struct node* insertNode(struct node* p, int x);
inline struct node* deleteNode(struct node* p, int x);
inline struct node* Min(struct node* p);
inline struct node* Max(struct node* p);

inline struct node* getnode(int x);
inline void display(struct node* p, int level);
inline struct node* search(struct node* p, int x);
inline struct node* insertNode(struct node* p, int x);
inline struct node* deleteNode(struct node* p, int x);
inline struct node* deleteNode1(struct node* root, int x);
inline struct node* Min(struct node* p);

inline void restoreUp(int a[], int loc);
inline void restoreDown(int a[], int i, int size);
inline void display1(int a[], int n);
inline void buildHeap_TopDown(int a[], int n);
inline void buildHeap_BottomUp(int a[], int n);

#define MAX 100
static struct node* queue[MAX];
static int front = -1, rear = -1;
inline void insertQueue(struct node* item);
static struct node* deleteQueue();
inline int queueEmpty();

int main()
{
	/* binary search tree non-recursive */

	int a[50];
	int n = 0;  /*size of heap*/
	int choice, value;

	struct node* root = NULL, * p;
	int x;

	while (1)
	{
		printf("\n");
		printf("1.Display Tree\n");
		printf("2.Search\n");
		printf("3.Insert a new node\n");
		printf("4.Delete a node\n");
		printf("5.Find minimum\n");
		printf("6.Find maximum\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 7)
			break;

		switch (choice)
		{
		case 1:
			display(root, 0);
			break;
		case 2:
			printf("Enter the key to be searched : ");
			scanf_s("%d", &x);
			p = search(root, x);
			if (p == NULL)
				printf("Key not found\n");
			else
				printf("Key found\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf_s("%d", &x);
			root = insertNode(root, x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf_s("%d", &x);
			root = deleteNode1(root, x);
			break;
		case 5:
			p = Min(root);
			if (p == NULL)
				printf("Tree is empty\n");
			else
				printf("Minimum key is %d\n", p->info);
			break;
		case 6:
			p = Max(root);
			if (p == NULL)
				printf("Tree is empty\n");
			else
				printf("Maximum key is %d\n", p->info);
			break;
		}/*End of switch*/
	}/*End of while */

	/* heap */

	a[0] = LARGE_VALUE;  /*Sentinel : All keys in heap should be less than this value*/

	while (1)
	{
		printf("1.Insert\n");
		printf("2.Delete root\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 4)
			break;
		switch (choice)
		{
		case 1:
			printf("Enter the value to be inserted : ");
			scanf_s("%d", &value);
			insert(value, a, &n);
			break;
		case 2:
			if (n == 0)
				printf("Heap is empty \n");
			else
			{
				value = deleteRoot(a, &n);
				printf("Maximum value is %d\n", value);
			}
			break;
		case 3:
			display(a, n);
			break;
		default:
			printf("Wrong choice\n");
		}
	}

	/* binary search tree recursive */

	// struct node* root = NULL, * p;
	choice, x;

	root = insertNode(root, 70);
	root = insertNode(root, 80);
	root = insertNode(root, 75);
	root = insertNode(root, 89);
	root = insertNode(root, 82);
	root = insertNode(root, 93);
	root = insertNode(root, 83);
	display(root, 0);
	root = deleteNode(root, 80);
	display(root, 0);

	while (1)
	{
		printf("\n");
		printf("1.Display Tree\n");
		printf("2.Search\n");
		printf("3.Insert a new node\n");
		printf("4.Delete a node\n");
		printf("5.Preorder Traversal\n");
		printf("6.Inorder Traversal\n");
		printf("7.Postorder Traversal\n");
		printf("8.Height of tree\n");
		printf("9.Find Minimum key\n");
		printf("10.Find Maximum key\n");
		printf("11.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 11)
			break;

		switch (choice)
		{
		case 1:
			display(root, 0);
			break;
		case 2:
			printf("Enter the key to be searched : ");
			scanf_s("%d", &x);
			p = search(root, x);
			if (p == NULL)
				printf("Key not found\n");
			else
				printf("Key found\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf_s("%d", &x);
			root = insertNode(root, x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf_s("%d", &x);
			root = deleteNode(root, x);
			break;
		case 5:
			preorder(root);
			break;
		case 6:
			inorder(root);
			break;
		case 7:
			postorder(root);
			break;
		case 8:
			printf("Height of tree is %d\n", height(root));
			break;
		case 9:
			p = Min(root);
			if (p == NULL)
				printf("Tree is empty\n");
			else
				printf("Minimum key is %d\n", p->info);
			break;
		case 10:
			p = Max(root);
			if (p == NULL)
				printf("Tree is empty\n");
			else
				printf("Maximum key is %d\n", p->info);
			break;
		}/*End of switch */
	}/*End of while */


	/* build heap */

	int a1[] = { LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12 };
	int a2[] = { LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12 };

	n = 12;

	buildHeap_TopDown(a1, n);
	buildHeap_BottomUp(a2, n);

	display1(a1, n);
	display1(a2, n);

	/* binary tree */

	// struct node* root = NULL;

	root = getnode('P');

	root->lchild = getnode('Q');
	root->rchild = getnode('R');
	root->lchild->lchild = getnode('A');
	root->lchild->rchild = getnode('B');
	root->rchild->lchild = getnode('X');

	display(root, 0);
	printf("\n\n");

	printf("Preorder : ");
	preorder(root);
	printf("\n\n");

	printf("Inorder : ");
	inorder(root);
	printf("\n\n");

	printf("Postorder : ");
	postorder(root);
	printf("\n\n");

	printf("Level order : ");
	levelOrder(root);
	printf("\n\n");

	printf("Height of tree is %d\n", height(root));

	getchar();
}

int deleteRoot(int a[], int* pn)
{
	int maxValue = a[1];
	a[1] = a[*pn];
	(*pn)--;
	restoreDown(a, 1, *pn);
	return maxValue;
}

void insert(int value, int a[], int* pn)
{
	(*pn)++;
	a[*pn] = value;
	restoreUp(a, *pn);
}

void buildHeap_TopDown(int a[], int n)
{
	int i;
	for (i = 2; i <= n; i++)
		restoreUp(a, i);
}

void buildHeap_BottomUp(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		restoreDown(a, i, n);
}

void restoreUp(int a[], int i)
{
	int k = a[i];
	int iparent = i / 2;

	while (a[iparent] < k)
	{
		a[i] = a[iparent];
		i = iparent;
		iparent = i / 2;
	}
	a[i] = k;
}

void restoreDown(int a[], int i, int n)
{
	int k = a[i];
	int lchild = 2 * i, rchild = lchild + 1;

	while (rchild <= n)
	{
		if (k >= a[lchild] && k >= a[rchild])
		{
			a[i] = k;
			return;
		}
		else if (a[lchild] > a[rchild])
		{
			a[i] = a[lchild];
			i = lchild;
		}
		else
		{
			a[i] = a[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}

	/*If number of nodes is even*/
	if (lchild == n && k < a[lchild])
	{
		a[i] = a[lchild];
		i = lchild;
	}
	a[i] = k;
}


struct node* getnode(int x)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

struct node* insertNode(struct node* p, int x)
{
	if (p == NULL)
		p = getnode(x);
	else if (x < p->info)
		p->lchild = insertNode(p->lchild, x);
	else if (x > p->info)
		p->rchild = insertNode(p->rchild, x);
	else
		printf("%d already present in tree\n", x);
	return p;
}/*End of insertNode()*/

struct node* search(struct node* p, int x)
{
	if (p == NULL)
		return NULL; /*key not found*/
	if (x < p->info)/*search in left subtree*/
		return search(p->lchild, x);
	if (x > p->info)/*search in right subtree*/
		return search(p->rchild, x);
	return p; /*key found*/
}/*End of search()*/

struct node* deleteNode(struct node* p, int x)
{
	struct node* ch, * s;

	if (p == NULL)
	{
		printf("%d not found\n", x);
		return p;
	}
	if (x < p->info)  /*delete from left subtree*/
		p->lchild = deleteNode(p->lchild, x);
	else if (x > p->info) /*delete from right subtree*/
		p->rchild = deleteNode(p->rchild, x);
	else
	{
		/*key to be deleted is found*/
		if (p->lchild != NULL && p->rchild != NULL)  /*2 children*/
		{
			s = p->rchild;
			while (s->lchild)
				s = s->lchild;
			p->info = s->info;
			p->rchild = deleteNode(p->rchild, s->info);
		}
		else   /*1 child or no child*/
		{
			if (p->lchild != NULL) /*only left child*/
				ch = p->lchild;
			else  /*only right child or no child*/
				ch = p->rchild;
			free(p);
			p = ch;
		}
	}
	return p;
}/*End of deleteNode()*/


struct node* Min(struct node* p)
{
	if (p == NULL)
		return NULL;
	if (p->lchild == NULL)
		return p;
	return Min(p->lchild);
}/*End of Min()*/

struct node* Max(struct node* p)
{
	if (p == NULL)
		return NULL;
	if (p->rchild == NULL)
		return p;
	return Max(p->rchild);
}/*End of Max()*/

void preorder(struct node* p)
{
	if (p == NULL)	/*Base Case*/
		return;
	printf("%d  ", p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}/*End of preorder( )*/

void inorder(struct node* p)
{
	if (p == NULL)/*Base Case*/
		return;
	inorder(p->lchild);
	printf("%d  ", p->info);
	inorder(p->rchild);
}/*End of inorder( )*/

void postorder(struct node* p)
{
	if (p == NULL)/*Base Case*/
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d  ", p->info);

}/*End of postorder()*/

int height(struct node* p)
{
	int hL, hR;

	if (p == NULL) /*Base Case*/
		return 0;

	hL = height(p->lchild);
	hR = height(p->rchild);

	if (hL > hR)
		return 1 + hL;
	else
		return 1 + hR;
}/*End of height()*/

void display(struct node* p, int level)
{
	int i;
	if (p == NULL)
		return;

	display(p->rchild, level + 1);
	printf("\n");

	for (i = 0; i < level; i++)
		printf("    ");
	printf("%d", p->info);

	display(p->lchild, level + 1);
}/*End of display()*/

void display1(int a[], int n)
{
	int i;
	if (n == 0)
	{
		printf("Heap is empty\n");
		return;
	}
	printf("Heap size = %d\n", n);
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//struct node* getnode(char x)
//{
//	struct node* p = (struct node*)malloc(sizeof(struct node));
//	p->info = x;
//	p->lchild = p->rchild = NULL;
//	return p;
//}

//void display(struct node* p, int level)
//{
//	int i;
//	if (p == NULL)
//		return;
//
//	display(p->rchild, level + 1);
//	printf("\n");
//
//	for (i = 0; i < level; i++)
//		printf("    ");
//	printf("%c", p->info);
//
//	display(p->lchild, level + 1);
//}/*End of display()*/

//void preorder(struct node* p)
//{
//	if (p == NULL)
//		return;
//	printf("%c  ", p->info);
//	preorder(p->lchild);
//	preorder(p->rchild);
//}/*End of preorder()*/

//void inorder(struct node* p)
//{
//	if (p == NULL)
//		return;
//	inorder(p->lchild);
//	printf("%c  ", p->info);
//	inorder(p->rchild);
//}/*End of inorder()*/

//void postorder(struct node* p)
//{
//	if (p == NULL)
//		return;
//	postorder(p->lchild);
//	postorder(p->rchild);
//	printf("%c  ", p->info);
//
//}/*End of postorder()*/

//int height(struct node* p)
//{
//	int hL, hR;
//
//	if (p == NULL)
//		return 0;
//
//	hL = height(p->lchild);
//	hR = height(p->rchild);
//
//	if (hL > hR)
//		return 1 + hL;
//	else
//		return 1 + hR;
//}/*End of height()*/

void levelOrder(struct node* p)
{
	if (p == NULL)
	{
		printf("Tree is empty\n");
		return;
	}

	insertQueue(p);
	while (!queueEmpty())
	{
		p = deleteQueue();
		printf("%c  ", p->info);
		if (p->lchild != NULL)
			insertQueue(p->lchild);
		if (p->rchild != NULL)
			insertQueue(p->rchild);
	}
}

/*Functions for implementation of queue*/
void insertQueue(struct node* item)
{
	if (rear == MAX - 1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if (front == -1)  /*If queue is initially empty*/
		front = 0;
	rear = rear + 1;
	queue[rear] = item;
}

struct node* deleteQueue()
{
	struct node* item;
	if (front == -1 || front == rear + 1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	item = queue[front];
	front = front + 1;
	return item;
}/*End of deleteQueue()*/

int queueEmpty()
{
	if (front == -1 || front == rear + 1)
		return 1;
	else
		return 0;
}

struct node* deleteNode1(struct node* root, int x)
{
	struct node* par, * p, * ch, * s, * ps;

	p = root;
	par = NULL;
	while (p != NULL)
	{
		if (x == p->info)
			break;
		par = p;
		if (x < p->info)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (p == NULL)
	{
		printf("%d not found\n", x);
		return root;
	}

	/*Case C: 2 children*/
	/*Find inorder successor and its parent*/
	if (p->lchild != NULL && p->rchild != NULL)
	{
		ps = p;
		s = p->rchild;
		while (s->lchild != NULL)
		{
			ps = s;
			s = s->lchild;
		}
		p->info = s->info;
		p = s;
		par = ps;
	}

	/*Case B and Case A : 1 or no child*/
	if (p->lchild != NULL) /*node to be deleted has left child */
		ch = p->lchild;
	else                /*node to be deleted has right child or no child*/
		ch = p->rchild;

	if (par == NULL)   /*node to be deleted is root node*/
		root = ch;
	else if (p == par->lchild)/*node is left child of its parent*/
		par->lchild = ch;
	else       /*node is right child of its parent*/
		par->rchild = ch;
	free(p);
	return root;
}