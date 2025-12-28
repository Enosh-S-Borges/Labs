// C program to implement Stack using Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;  

void push(int value) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("\nMemory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed to stack.\n", value);
}

void pop() 
{
    if (top == NULL) 
    {
        printf("\nStack Underflow! Cannot pop.\n");
        return;
    }

    Node *temp = top;
    printf("\nPopped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek() 
{
    if (top == NULL) 
    {
        printf("\nStack is empty!\n");
        return;
    }
    printf("\nTop element: %d\n", top->data);
}

void display() 
{
    if (top == NULL) 
    {
        printf("\nStack is empty!\n");
        return;
    }

    Node *temp = top;
    printf("\nStack elements: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    int choice, value;
    while (1) 
    {
        printf("\n===== STACK USING LINKED LIST =====");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}