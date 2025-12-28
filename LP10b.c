/* 10.b) Develop a menu driven program to implement Circular Queue with static and 
dynamic memory allocation mechanisms.(Represent Queue using structure) */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct 
{
    int *arr;
    int front, rear;
    int size;
    int isDynamic;
} CQueue;

void initSMA(CQueue *q) 
{
    q->size = MAX;
    q->arr = (int *)malloc(sizeof(int) * MAX);
    q->front = q->rear = MAX - 1;
    q->isDynamic = 0;
}

void initDMA(CQueue *q, int size) 
{
    q->size = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = size - 1;
    q->isDynamic = 1;
}

int isEmpty(CQueue *q) 
{
    return q->front == q->rear;
}

int isFull(CQueue *q) 
{
    return (q->rear + 1) % q->size == q->front;
}

void resizeQueue(CQueue *q) 
{
    int newSize = q->size * 2;
    int *newArr = (int *)malloc(sizeof(int) * newSize);

    int i = 0;
    int idx = (q->front + 1) % q->size;

    while (idx != (q->rear + 1) % q->size) 
    {
        newArr[i++] = q->arr[idx];
        idx = (idx + 1) % q->size;
    }

    free(q->arr);
    q->arr = newArr;
    q->size = newSize;
    q->front = newSize - 1;
    q->rear = i - 1;
}

void enqueue(CQueue *q, int item) 
{
    if (isFull(q)) 
    {
        printf("Queue is FULL\n");
        if (q->isDynamic) 
        {
            printf("Allocating more memory\n");
            resizeQueue(q);
        } 
        else 
        {
            return;
        }
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = item;
}

void dequeue(CQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    q->front = (q->front + 1) % q->size;
    printf("Dequeued: %d\n", q->arr[q->front]);
}

void peekFront(CQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Front: %d\n", q->arr[(q->front + 1) % q->size]);
}

void peekRear(CQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Rear: %d\n", q->arr[q->rear]);
}

void display(CQueue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is EMPTY\n");
        return;
    }

    int i = (q->front + 1) % q->size;
    while (i != (q->rear + 1) % q->size) 
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() 
{
    CQueue q;
    int choice, op, val, size;

    printf("1. Static Memory Allocation\n");
    printf("2. Dynamic Memory Allocation\n");
    scanf("%d", &choice);

    if (choice == 1)
        initSMA(&q);
    else if (choice == 2) 
    {
        printf("Enter size: ");
        scanf("%d", &size);
        initDMA(&q, size);
    } 
    else
        return 0;
    printf("\n--- Static Circular Queue and Dynamic Circular Queue Menu ---\n");
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Peek Rear\n5.Display\n6.Exit\n");
        scanf("%d", &op);

        switch (op) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peekFront(&q);
                break;
            case 4:
                peekRear(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                break;
            default:
                printf("Invalid\n");
        }
    } while (op != 6);
    free(q.arr);
    return 0;
}