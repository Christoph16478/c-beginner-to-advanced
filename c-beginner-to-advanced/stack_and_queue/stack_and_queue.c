#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//struct node
//{
//	int info;
//	struct node* link;
//};
//
//struct node* front, * rear;

//void initializeQueue();
//int size();
//void insert(int x);
//int Delete();
//int peek();
//int isEmpty();
//void display();

#define MAX 100

void infixToPostfix(char infix[], char postfix[]);
long int evaluatePostfix(char postfix[]);
int precedence(char symbol);
int power(int b, int a);

// long int stack[MAX];
int top = -1;
void push(long int symbol);
// long int pop();
int isEmpty();

struct node
{
	int priority;
	int info;
	struct node* link;
};

struct node* front, * rear;
//
//struct node* front;

int a[MAX];
//int front;
//int rear;

inline void initializeQueue();
char stack[MAX];
int top;
inline void insert(int x);
inline void initializeStack();
inline void push(char);
inline char pop();
inline int isEmpty();
inline int Delete();
inline void display();
inline int size();

inline int isValid(char exp[]);
inline int matchParentheses(char leftPar,char rightPar);

//void initializeQueue()
//{
//	rear = -1;
//	front = -1;
//}

int main()
{
	int choice, element, elementPriority, x;

	/* infix to postfix */
	char infix[MAX], postfix[MAX];

	printf("Enter infix expression: ");
	gets(infix);

	infixToPostfix(infix, postfix);
	printf("Postfix expression is : %s\n", postfix);
	printf("Value of expression : %ld\n", evaluatePostfix(postfix));


	/* queue-using-array */

	while (1)
	{
		printf("1.Insert an element in the queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Display size of the queue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 6)
			break;

		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &x);
			insert(x);
			break;
		case 2:
			x = Delete();
			printf("Element Deleted is : %d\n", x);
			break;
		case 3:
			printf("Element at the front is : %d\n", peek());
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Size of queue is %d\n", size());
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}

	/* stack-using-linked-list */

	while (1)
	{
		printf("1.Insert an element in the queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Display size of the queue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 6)
			break;

		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &x);
			insert(x);
			break;
		case 2:
			x = Delete();
			printf("Element Deleted is : %d\n", x);
			break;
		case 3:
			printf("Element at the front is : %d\n", peek());
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Size of the queue is %d\n", size());
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}

	/* stack using array */

	while (1)
	{
		printf("1.Push an element on the stack\n");
		printf("2.Pop an element from the stack\n");
		printf("3.Display the top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Display size of the stack\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 6)
			break;
		switch (choice)
		{
		case 1:
			printf("Enter the element to be pushed : ");
			scanf_s("%d", &x);
			push(x);
			break;
		case 2:
			x = pop();
			printf("Popped element is : %d\n", x);
			break;
		case 3:
			printf("Element at the top is : %d\n", peek());
			break;
		case 4:
			display();
			break;
		case 5:
			// printf("Size of stack = %d\n", size());
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}


	/* queue using circular linked list */


	// initializeQueue();

	while (1)
	{
		printf("1.Insert an element in the queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Display size of the queue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 6)
			break;

		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &x);
			// insert(x);
			break;
		case 2:
			x = Delete();
			printf("Element Deleted is : %d\n", x);
			break;
		case 3:
			printf("Element at the front is : %d\n", peek());
			break;
		case 4:
			display();
			break;
		case 5:
			// printf("Size of the queue is %d\n", size());
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}

	/* queue using array */



	// initializeQueue();

	// int front = -1;

	while (1)
	{
		printf("1.Insert a new element\n");
		printf("2.Delete an element\n");
		printf("3.Display the queue\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf_s("%d", &choice);
		if (choice == 4)
			break;

		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf_s("%d", &element);
			printf("Enter its priority : ");
			scanf_s("%d", &elementPriority);
			// insert(element, elementPriority);
			break;
		case 2:
			printf("Deleted element is %d\n", Delete());
			break;
		case 3:
			display();
			break;
		default:
			printf("Wrong choice\n");
		}
	}

	/* balanced parantheses */

	char expression[MAX];

	choice = 'y';

	while (choice == 'y')
	{
		printf("Enter an expression with parentheses : ");
		gets(expression);

		initializeStack();

		if (isValid(expression))
			printf("Valid expression\n");
		else
			printf("Invalid expression\n");

		printf("Want to check another expression (Enter 'y' for yes) : ");
		scanf_s("%c", &choice);
		fflush(stdin);
	}

	return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
	unsigned int i, p;
	char next, symbol;

	p = 0;
	for (i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];

		if (symbol == ' ' || symbol == '\t') /*ignore blanks and tabs*/
			continue;

		switch (symbol)
		{
		case '(':
			push(symbol);
			break;
		case ')':
			while ((next = pop()) != '(')
				postfix[p++] = next;
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
				postfix[p++] = pop();
			push(symbol);
			break;
		default: /*operand*/
			postfix[p++] = symbol;
		}
	}
	while (!isEmpty())
		postfix[p++] = pop();
	postfix[p] = '\0'; /*Add '\0' to make postfix a string*/
}

int precedence(char symbol)
{
	switch (symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

//void push(long int symbol)
//{
//	if (top > MAX)
//	{
//		printf("Stack overflow\n");
//		exit(1);
//	}
//	stack[++top] = symbol;
//}

//char pop()
//{
//	if (isEmpty())
//	{
//		printf("Stack underflow\n");
//		exit(1);
//	}
//	return (stack[top--]);
//}

//int isEmpty()
//{
//	if (top == -1)
//		return 1;
//	else
//		return 0;
//}

long int evaluatePostfix(char postfix[])
{
	long int x, y, result;
	unsigned int i;

	for (i = 0; i < strlen(postfix); i++)
	{
		if (postfix[i] <= '9' && postfix[i] >= '0')
			push(postfix[i] - '0');
		else
		{
			x = pop();
			y = pop();
			switch (postfix[i])
			{
			case '+':
				push(y + x); break;
			case '-':
				push(y - x); break;
			case '*':
				push(y * x); break;
			case '/':
				push(y / x); break;
			case '%':
				push(y % x); break;
			case '^':
				push(power(y, x));
			}
		}
	}
	result = pop();
	return result;
}

int power(int b, int a)
{
	int i, x = 1;
	for (i = 1; i <= a; i++)
		x = x * b;
	return x;
}

int size()
{
	return top + 1;
}

void insert(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Memory not available\n");
		return;
	}
	temp->info = x;
	temp->link = NULL;

	if (front == NULL)		 /*If Queue is empty*/
		front = temp;
	else
		rear->link = temp;
	rear = temp;
}

int isValid(char expr[])
{
	int i;
	char ch;

	for(i=0; i<strlen(expr); i++)
	{
		if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
			push(expr[i]);

		if(expr[i]==')' || expr[i]=='}' || expr[i]==']')
			if(isEmpty())
			{
				printf("Right parentheses are more than left parentheses\n");
				return 0;
			}
			else
			{
				ch=pop();
				if(!matchParentheses(ch,expr[i]))
				{
					printf("Mismatched parentheses are : ");
					printf("%c and %c\n",ch,expr[i]);
					return 0;
				}
			}
	}

	if(isEmpty())
	{
		printf("Balanced Parentheses\n");
		return 1;
	}
	else
	{
		printf("Left parentheses are more than right parentheses\n");
		return 0;
	}
}

int matchParentheses(char leftPar,char rightPar)
{
	if(leftPar=='[' && rightPar==']')
		return 1;
	if(leftPar=='{' && rightPar=='}')
		return 1;
	if(leftPar=='(' && rightPar==')')
		return 1;
	return 0;
}

void push(char x)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack[top]=x;
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return(stack[top--]);
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void initializeStack()
{
	top=-1;
}

int Delete()
{
	int x;
	int front = 1;
	if (isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	x = a[front];
	front = front + 1;
	return x;
}

int peek()
{
	int front = 0;
	if (isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return a[front];
}

void display()
{
	int i;

	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Queue is :\n\n");
	for (i = front; i <= rear; i++)
		printf("%d  ", a[i]);

	printf("\n\n");
}

//void insert(int x)
//{
//	if (isFull())
//	{
//		printf("Queue Overflow\n");
//		return;
//	}
//	if (front == -1)
//		front = 0;
//	rear = rear + 1;
//	a[rear] = x;
//}

