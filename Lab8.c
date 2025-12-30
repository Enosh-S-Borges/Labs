/*Develop a menu driven program to implement Stack with static and
dynamic memory allocation mechanisms. (Represent Stack using
structure)*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack
{
	int top;
	int size;
	int *arr;
	int staticArr[MAX];
} Stack;

void pushStatic(Stack *s, int value);
int popStatic(Stack *s);
int peekStatic(Stack *s);
void displayStatic(Stack *s);
void pushDynamic(Stack *s, int value);
int popDynamic(Stack *s);
int peekDynamic(Stack *s);
void displayDynamic(Stack *s);

int main()
{
	Stack staticStack = {.top = -1, .size = MAX};
	Stack dynamicStack = {.top = -1, .size = 0, .arr = NULL};
	int choice, value, maxSize;

	printf("Enter the initial maximum size for dynamic stack: ");
	scanf("%d", &maxSize);

	dynamicStack.size = maxSize;
	dynamicStack.arr = (int*)malloc(maxSize * sizeof(int));
	if (dynamicStack.arr == NULL)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	do
	{
		printf("\n===== Stack Menu =====\n");
		printf("1. Push (Static Stack)\n");
		printf("2. Pop (Static Stack)\n");
		printf("3. Peek (Static Stack)\n");
		printf("4. Display (Static Stack)\n");
		printf("5. Push (Dynamic Stack)\n");
		printf("6. Pop (Dynamic Stack)\n");
		printf("7. Peek (Dynamic Stack)\n");
		printf("8. Display (Dynamic Stack)\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter value to push (Static Stack): ");
				scanf("%d", &value);
				pushStatic(&staticStack, value);
				break;
			case 2:
				value = popStatic(&staticStack);
				if (value != -1)
					printf("Popped: %d\n", value);
				break;
			case 3:
				value = peekStatic(&staticStack);
				if (value != -1)
					printf("Top element: %d\n", value);
				break;
			case 4:
				displayStatic(&staticStack);
				break;
			case 5:
				printf("Enter value to push (Dynamic Stack): ");
				scanf("%d", &value);
				pushDynamic(&dynamicStack, value);
				break;
			case 6:
				value = popDynamic(&dynamicStack);
				if (value != -1)
					printf("Popped: %d\n", value);
				break;
			case 7:
				value = peekDynamic(&dynamicStack);
				if (value != -1)
					printf("Top element: %d\n", value);
				break;
			case 8:
				displayDynamic(&dynamicStack);
				break;
			case 9:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice! Try again.\n");
		}
	} while (choice != 9);

	free(dynamicStack.arr);
	return 0;
}

void pushStatic(Stack *s, int value)
{
	if (s->top == s->size - 1)
	{
		printf("Stack Overflow (Static Stack)!\n");
	}
	else
	{
		s->top++;
		s->staticArr[s->top] = value;
		printf("%d pushed to static stack.\n", value);
	}
}

int popStatic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Stack Underflow (Static Stack)!\n");
		return -1;
	}
	else
	{
		return s->staticArr[s->top--];
	}
}

int peekStatic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Static stack is empty!\n");
		return -1;
	}
	else
	{
		return s->staticArr[s->top];
	}
}

void displayStatic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Static stack is empty!\n");
	}
	else
	{
		printf("Static Stack: ");
		for (int i = s->top; i >= 0; i--)
			printf("%d ", s->staticArr[i]);
		printf("\n");
	}
}

// ===== Dynamic Stack Functions =====
void pushDynamic(Stack *s, int value)
{
	if (s->top == s->size - 1)
	{
		int newSize = s->size * 2;
		int *newArr = (int*)realloc(s->arr, newSize * sizeof(int));
		if (newArr == NULL)
		{
			printf("Memory reallocation failed!\n");
			return;
		}
		s->arr = newArr;
		s->size = newSize;
		printf("Dynamic stack capacity increased to %d.\n", s->size);
	}
	s->top++;
	s->arr[s->top] = value;
	printf("%d pushed to dynamic stack.\n", value);
}

int popDynamic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Stack Underflow (Dynamic Stack)!\n");
		return -1;
	}
	else
	{
		return s->arr[s->top--];
	}
}

int peekDynamic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Dynamic stack is empty!\n");
		return -1;
	}
	else
	{
		return s->arr[s->top];
	}
}

void displayDynamic(Stack *s)
{
	if (s->top == -1)
	{
		printf("Dynamic stack is empty!\n");
	}
	else
	{
		printf("Dynamic Stack: ");
		for (int i = s->top; i >= 0; i--)
			printf("%d ", s->arr[i]);
		printf("\n");
	}
}