#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node* prev;
	int info;
	struct node* link;
	struct node* next;
};

inline struct node* createList(struct node* start);
inline void displayList(struct node* start);
inline void countNodes(struct node* start);
inline void search(struct node* start, int x);
inline struct node* insertInEmptyList(struct node* start, int data);
inline struct node* insertInBeginning(struct node* start, int data);
inline void insertAtEnd(struct node* start, int data);
inline struct node* insertAtEnd1(struct node* last, int data);
inline void insertAfter(struct node* start, int data, int x);
inline struct node* insertAfter1(struct node* last, int data, int x);
inline struct node* insertBefore(struct node* start, int data, int x);
inline struct node* insertAtPosition(struct node* start, int data, int k);
inline struct node* deleteNode(struct node* start, int data);
inline struct node* reverseList(struct node* start);
inline void reverse(struct node* head);
inline void SortByExchangingData(struct node* start);
inline struct node* SortByExchangingLinks(struct node* start);
inline struct node* concatenate(struct node* start1, struct node* start2);
inline struct node* merge(struct node* p1, struct node* p2);
inline struct node* createSortedList(struct node* start);
inline struct node* insertInOrder(struct node* start, int data);

inline struct node* createList(struct node* start);
inline void insertCycle(struct node* start, int x);
inline struct node* findCycle(struct node* start);
inline void removeCycle(struct node* start, struct node* pC);

int main()
{
	/* merging sorted list */
	struct node* start1 = NULL, * start2 = NULL, * startM;
	start1 = createSortedList(start1);
	start2 = createSortedList(start2);
	printf("List1 : ");
	displayList(start1);
	printf("List2 : ");
	displayList(start2);
	startM = merge(start1, start2);
	displayList(startM);

	int choice, data, item, x, k;
	struct node* last = NULL;
	struct node* start = NULL;
	struct node* ptr;
	start = createList(start);
	last = createList(last);
	struct node* head;

	/* merging sorted list */
	// struct node* start1 = NULL, * start2 = NULL, * startM;
	start1 = createSortedList(start1);
	start2 = createSortedList(start2);
	printf("List1 : ");
	displayList(start1);
	printf("List2 : ");
	displayList(start2);
	startM = merge(start1, start2);
	displayList(startM);

	/* concatenate circular linked list */
	struct node* last1 = NULL, * last2 = NULL;
	last1 = createList(last1);
	last2 = createList(last2);
	printf("First list is :  ");	displayList(last1);
	printf("Second list is :  ");	displayList(last2);
	last1 = concatenate(last1, last2);

	printf("Concatenated list is  : "); 	displayList(last1);

	/* concatenate linked lists */
	// struct node* start1 = NULL, * start2 = NULL;
	start1 = createList(start1);
	start2 = createList(start2);
	printf("First list is  : ");	displayList(start1);
	printf("Second list is  : ");	displayList(start2);
	start1 = concatenate(start1, start2);
	printf("Concatenated list is  : ");	displayList(start1);

	/* bubble sort linked list */
	// struct node* start1 = NULL, * start2 = NULL;
	printf("Create first list \n");
	start1 = createList(start1);
	SortByExchangingData(start1);
	displayList(start1);
	printf("Create second list \n");
	start2 = createList(start2);
	start2 = SortByExchangingLinks(start2);
	displayList(start2);

	/* merge sorted linked list */
	start = createList(start);
	// start = mergeSort(start);
	displayList(start);

	/* cycle in linked list */
	start = createList(start);

	if (start == NULL)
		exit(1);

	x = 40;
	insertCycle(start, x);

	ptr = findCycle(start);

	if (ptr == NULL)
		printf("List is NULL terminated\n");
	else
	{
		printf("Cycle found in the list\n");
		removeCycle(start, ptr);
		printf("Cycle Removed, now list is NULL terminated\n");
	}
	displayList(start);

	/* single linked list header node */
	head = (struct node*)malloc(sizeof(struct node));
	head->info = 0;
	head->link = NULL;

	createList(head);

	while (1)
	{
		printf("1.Display list\n");
		printf("2.Insert a node at the end of the list\n");
		printf("3.Insert a new node before a node\n");
		printf("4.Insert at a given position\n");
		printf("5.Delete a node\n");
		printf("6.Reverse the list\n");
		printf("7.Quit\n\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 7)
			break;

		switch (choice)
		{
		case 1:
			displayList(head);
			break;
		case 2:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			insertAtEnd1(head, data);
			break;
		case 3:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element before which to insert : ");
			scanf_s("%d", &x);
			insertBefore(head, data, x);
			break;
		case 4:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the position at which to insert : ");
			scanf_s("%d", &k);
			insertAtPosition(head, data, k);
			break;
		case 5:
			printf("Enter the element to be deleted : ");
			scanf_s("%d", &data);
			deleteNode(head, data);
			break;
		case 6:
			reverse(head);
			break;
		default:
			printf("Wrong choice\n\n");
		}
	}/*End of while */


	/* circular linked list */
	while (1)
	{
		printf("1.Display List\n");
		printf("2.Insert in  empty list\n");
		printf("3.Insert in the beginning\n");
		printf("4.Insert at the end\n");
		printf("5.Insert after a node\n");
		printf("6.Delete a node\n");
		printf("7.Quit\n");

		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 7)
			break;
		switch (choice)
		{
		case 1:
			displayList(last);
			break;
		case 2:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			last = insertInEmptyList(last, data);
			break;
		case 3:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			last = insertInBeginning(last, data);
			break;
		case 4:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			last = insertAtEnd1(last, data);
			break;
		case 5:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element after which to insert : ");
			scanf_s("%d", &item);
			last = insertAfter1(last, data, item);
			break;
		case 6:
			printf("Enter the element to be deleted : ");
			scanf_s("%d", &data);
			last = deleteNode(last, data);
			break;
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/

	/* double linked list */
	// int choice, data, x, k;
	// struct node* start = NULL;

	// start = createList(start);

	while (1)
	{
		printf("\n");
		printf("1.Display List\n");
		printf("2.Insert in empty list\n");
		printf("3.Insert a node in beginning of the list\n");
		printf("4.Insert a node at the end of the list\n");
		printf("5.Insert a node after a specified node\n");
		printf("6.Insert a node before a specified node\n");
		printf("7.Delete a node\n");
		printf("8.Reverse the list\n");
		printf("9.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 9)
			break;

		switch (choice)
		{
		case 1:
			displayList(start);
			break;
		case 2:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			start = insertInEmptyList(start, data);
			break;
		case 3:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			start = insertInBeginning(start, data);
			break;
		case 4:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			insertAtEnd(start, data);
			break;
		case 5:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element after which to insert : ");
			scanf_s("%d", &x);
			insertAfter(start, data, x);
			break;
		case 6:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element before which to insert : ");
			scanf_s("%d", &x);
			start = insertBefore(start, data, x);
			break;
		case 7:
			printf("Enter the element to be deleted : ");
			scanf_s("%d", &data);
			start = deleteNode(start, data);
			break;
		case 8:
			start = reverseList(start);
			break;
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/


	/* sorted linked list */
	// struct node* start = NULL;
	// int choice, data, x, k;

	// start = createList(start);

	while (1)
	{
		printf("\n");
		printf("1.Display list\n");
		printf("2.Count the number of nodes\n");
		printf("3.Search for an element\n");
		printf("4.Insert in empty list / Insert in beginning of the list\n");
		printf("5.Insert a node at the end of the list\n");
		printf("6.Insert a node after a specified node\n");
		printf("7.Insert a node before a specified node\n");
		printf("8.Insert a node at a given position\n");
		printf("9.Delete a node\n");
		printf("10.Reverse the list\n");
		printf("11.Quit\n\n");

		printf("Enter your choice : ");
		scanf_s("%d", &choice);

		if (choice == 11)
			break;

		switch (choice)
		{
		case 1:
			displayList(start);
			break;
		case 2:
			countNodes(start);
			break;
		case 3:
			printf("Enter the element to be searched : ");
			scanf_s("%d", &data);
			search(start, data);
			break;
		case 4:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			start = insertInBeginning(start, data);
			break;
		case 5:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			insertAtEnd(start, data);
			break;
		case 6:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element after which to insert : ");
			scanf_s("%d", &x);
			insertAfter(start, data, x);
			break;
		case 7:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the element before which to insert : ");
			scanf_s("%d", &x);
			start = insertBefore(start, data, x);
			break;
		case 8:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &data);
			printf("Enter the position at which to insert : ");
			scanf_s("%d", &k);
			start = insertAtPosition(start, data, k);
			break;
		case 9:
			printf("Enter the element to be deleted : ");
			scanf_s("%d", &data);
			start = deleteNode(start, data);
			break;
		case 10:
			start = reverseList(start);
			break;
		default:
			printf("Wrong choice\n");
		}
	}
}/*End of main*/

struct node* insertInOrder(struct node* start, int data)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	/*List empty or new node to be inserted before first node*/
	if (start == NULL || data < start->info)
	{
		temp->link = start;
		start = temp;
		return start;
	}
	else
	{
		p = start;
		while (p->link != NULL && p->link->info < data)
			p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}/*End of insertInOrder()*/

struct node* createSortedList(struct node* start)
{
	int i, n, data;
	printf("Enter the number of nodes : ");
	scanf_s("%d", &n);
	start = NULL;

	for (i = 1; i <= n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf_s("%d", &data);
		start = insertInOrder(start, data);
	}
	return start;
}/*End of createSortedList()*/

struct node* merge(struct node* p1, struct node* p2)
{
	struct node* startM, * temp, * pM;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = NULL;
	startM = temp;

	if (p1->info <= p2->info)
	{
		temp->info = p1->info;
		p1 = p1->link;
	}
	else
	{
		temp->info = p2->info;
		p2 = p2->link;
	}

	pM = startM;
	while (p1 != NULL && p2 != NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		if (p1->info <= p2->info)
		{
			temp->info = p1->info;
			p1 = p1->link;
		}
		else
		{
			temp->info = p2->info;
			p2 = p2->link;
		}
		temp->link = NULL;
		pM->link = temp;
		pM = temp;
	}

	/*second list has finished and elements left in first list*/
	while (p1 != NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = p1->info;
		temp->link = NULL;
		pM->link = temp;
		pM = temp;

		p1 = p1->link;
	}

	/*If first list has finished and elements left in second list*/
	while (p2 != NULL)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = p2->info;
		temp->link = NULL;
		pM->link = temp;
		pM = temp;

		p2 = p2->link;
	}

	return startM;
}

void SortByExchangingData(struct node* start)
{
	struct node* end, * p, * q;
	int temp;

	for (end = NULL; end != start->link; end = p)
	{
		for (p = start; p->link != end; p = p->link)
		{
			q = p->link;
			if (p->info > q->info)
			{
				temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
}/*End of SortByExchangingData( )*/

struct node* SortByExchangingLinks(struct node* start)
{
	struct node* end, * r, * p, * q, * temp;

	for (end = NULL; end != start->link; end = p)
	{
		for (r = p = start; p->link != end; r = p, p = p->link)
		{
			q = p->link;
			if (p->info > q->info)
			{
				p->link = q->link;
				q->link = p;
				if (p != start)
					r->link = q;
				else
					start = q;
				temp = p;
				p = q;
				q = temp;
			}
		}

	}
	return start;
}/*End of SortByExchangingLinks()*/

struct node* concatenate(struct node* start1, struct node* start2)
{
	struct node* p;

	if (start1 == NULL)
	{
		start1 = start2;
		return start1;
	}

	if (start2 == NULL)
		return start1;

	p = start1;
	while (p->link != NULL)
		p = p->link;

	p->link = start2;

	return start1;
}

//void SortByExchangingData(struct node* start)
//{
//	struct node* end, * p, * q;
//	int temp;
//
//	for (end = NULL; end != start->link; end = p)
//	{
//		for (p = start; p->link != end; p = p->link)
//		{
//			q = p->link;
//			if (p->info > q->info)
//			{
//				temp = p->info;
//				p->info = q->info;
//				q->info = temp;
//			}
//		}
//	}
//}/*End of SortByExchangingData( )*/

/*Insert a cycle at node containing x*/
void insertCycle(struct node* start, int x)
{
	struct node* p, * px = NULL, * prev, * ptr;

	p = start;
	prev = p;
	while (p != NULL)
	{
		if (p->info == x)
			px = p;
		prev = p;
		p = p->link;
	}
	if (px != NULL)
		prev->link = px;
}

/*Returns NULL if the list is NULL terminated otherwise returns
pointer to node where both slow and fast pointers meet*/
struct node* findCycle(struct node* start)
{
	struct node* slowP, * fastP;

	if (start->link == NULL) /*only one element*/
		return NULL;

	slowP = fastP = start;

	while (fastP != NULL && fastP->link != NULL)
	{
		slowP = slowP->link;
		fastP = fastP->link->link;
		if (slowP == fastP)
			return slowP;
	}
	return NULL;
}/*End of findCycle()*/

void removeCycle(struct node* start, struct node* pC)
{
	struct node* p, * q;
	int i, lenCycle, lenRemList, lengthList;

	printf("Node at which the cycle was detected is %d\n", pC->info);

	p = q = pC;
	lenCycle = 0;
	do
	{
		lenCycle++;
		q = q->link;
	} while (p != q);
	printf("Length of cycle is : %d\n", lenCycle);

	lenRemList = 0;
	p = start;
	while (p != q)
	{
		lenRemList++;
		p = p->link;
		q = q->link;
	}

	printf("Number of nodes not included in the cycle are : %d\n", lenRemList);

	lengthList = lenCycle + lenRemList;
	printf("Length of the list is : %d\n", lengthList);

	p = start;
	for (i = 1; i <= lengthList - 1; i++)
		p = p->link;
	p->link = NULL;
}

struct node* createList(struct node* start)
{
	int i, n, data;
	printf("Enter the number of nodes : ");
	scanf_s("%d", &n);
	start = NULL;
	if (n == 0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf_s("%d", &data);
	start = insertInBeginning(start, data);

	for (i = 2; i <= n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf_s("%d", &data);
		start = insertAtEnd1(start, data);
	}
	return start;
}/*End of createList()*/

//void displayList(struct node* start)
//{
//	struct node* p;
//	if (start == NULL)
//	{
//		printf("List is empty\n");
//		return;
//	}
//	p = start;
//	printf("List is :\n");
//	while (p != NULL)
//	{
//		printf("%d ", p->info);
//		p = p->link;
//	}
//	printf("\n\n");
//}/*End of displayList() */

struct node* insertInBeginning(struct node* start, int data)
{
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}/*End of insertInBeginning()*/

//struct node* insertAtEnd1(struct node* start, int data)
//{
//	struct node* p, * tmp;
//	tmp = (struct node*)malloc(sizeof(struct node));
//	tmp->info = data;
//	p = start;
//	while (p->link != NULL)
//		p = p->link;
//	p->link = tmp;
//	tmp->link = NULL;
//	return start;
//}/*End of addAtEnd()*/

struct node* insertAfter1(struct node* last, int data, int x)
{
	struct node* temp, * p;
	p = last->link;
	do
	{
		if (p->info == x)
			break;
		p = p->link;
	} while (p != last->link);

	if (p == last->link && p->info != x)
		printf("%d not present in the list\n", x);
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;

		temp->link = p->link;
		p->link = temp;
		if (p == last)
			last = temp;
	}
	return last;
}/*End of insertAfter()*/

void insertAfter(struct node* start, int data, int x)
{
	struct node* temp, * p;

	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		p = p->link;
	}

	if (p == NULL)
		printf("%d not present in the list\n", x);
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
}

struct node* insertBefore(struct node* start, int data, int x)
{
	struct node* temp, * p;

	/*If list is empty*/
	if (start == NULL)
	{
		printf("List is empty\n");
		return start;
	}

	/*x is in first node,new node is to be inserted before first node*/
	if (x == start->info)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}

	/*Find pointer to predecessor of node containing x*/
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}

	if (p->link == NULL)
		printf("%d not present in the list\n", x);
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

struct node* insertAtPosition(struct node* start, int data, int k)
{
	struct node* temp, * p;
	int i;

	if (k == 1)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}

	p = start;
	for (i = 1; i < k - 1 && p != NULL; i++) /*find a pointer to k-1 node*/
		p = p->link;

	if (p == NULL)
		printf("You can insert only upto %dth position\n\n", i);
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

//struct node* createList(struct node* start)
//{
//	int i, n, data;
//
//	printf("Enter the number of nodes : ");
//	scanf_s("%d", &n);
//
//	if (n == 0)
//		return start;
//
//	printf("Enter the first element to be inserted : ");
//	scanf_s("%d", &data);
//	start = insertInBeginning(start, data);
//
//	for (i = 2; i <= n; i++)
//	{
//		printf("Enter the next element to be inserted : ");
//		scanf_s("%d", &data);
//		insertAtEnd(start, data);
//	}
//	return start;
//}/*End of createList()*/

struct node* insertInEmptyList(struct node* start, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	temp->prev = NULL;
	temp->next = NULL;
	start = temp;
	return start;
}/*End of insertInEmptyList( )*/

//struct node* insertInBeginning(struct node* start, int data)
//{
//	struct node* temp;
//	temp = (struct node*)malloc(sizeof(struct node));
//	temp->info = data;
//
//	temp->link = start;
//	start = temp;
//
//	return start;
//}

struct node* insertAtEnd1(struct node* last, int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	temp->link = last->link;
	last->link = temp;
	last = temp;
	return last;
}/*End of insertAtEnd( )*/

void insertAtEnd(struct node* start, int data)
{
	struct node* p, * temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;

	p = start;
	while (p->link != NULL)
		p = p->link;

	p->link = temp;
	temp->link = NULL;
}

void displayList(struct node* start)
{
	struct node* p;
	if (start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is :   ");
	p = start;
	while (p != NULL)
	{
		printf("%d  ", p->info);
		p = p->link;
	}
	printf("\n");
}/*End of displayList()*/

void countNodes(struct node* start)
{
	int n = 0;
	struct node* p = start;
	while (p != NULL)
	{
		n++;
		p = p->link;
	}
	printf("Number of nodes in list = %d\n", n);
}/*End of countNodes() */

void search(struct node* start, int x)
{
	struct node* p;

	int position = 1;
	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		position++;
		p = p->link;
	}
	if (p == NULL)
		printf("%d not found in list\n", x);
	else
		printf("%d is at position %d\n", x, position);
}/*End of search()*/

struct node* deleteNode(struct node* start, int x)
{
	struct node* temp, * p;
	if (start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	/*Deletion of first node*/
	if (start->info == x)
	{
		temp = start;
		start = start->link;
		free(temp);
		return start;
	}
	/*Deletion in between or at the end*/
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}

	if (p->link == NULL)
		printf("Element %d not in list\n\n", x);
	else
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
	}
	return start;
}

struct node* reverseList(struct node* start)
{
	struct node* prev, * ptr, * next;
	prev = NULL;
	ptr = start;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}/*End of reverseList()*/

void reverse(struct node* head)
{
	struct node* prev, * ptr, * next;
	prev = NULL;
	ptr = head->link;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	head->link = prev;
}/*End of reverse()*/