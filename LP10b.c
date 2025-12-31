/*b) Develop a menu driven program to implement Circular Queue with
static and dynamic memory allocation mechanisms.(Represent Queue
using structure)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5



typedef struct 
{
    int arr[MAX];   
    int *dynArr;   
    int front, rear;
    int size;       
} CQueue;

int isEmptyS(CQueue *q) 
{
    return q->front == -1;
}

int isFullS(CQueue *q) 
{
    return ((q->rear + 1) % MAX == q->front);
}

void enqueueS(CQueue *q, int val) 
{
    if (isFullS(q)) 
    {
        printf("Static Circular Queue is FULL. Cannot insert %d\n", val);
        return;
    }
    if (isEmptyS(q)) 
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
    printf("%d enqueued in Static Circular queue\n", val);
}

void dequeueS(CQueue *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Circular Queue is EMPTY\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    if (q->front == q->rear) 
        q->front = q->rear = -1;
    else 
        q->front = (q->front + 1) % MAX;
}

void displayS(CQueue *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Circular Queue is EMPTY\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = q->front;
    while (1) 
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void peekFrontS(CQueue *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Circular Queue is EMPTY\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void peekRearS(CQueue *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Circular Queue is EMPTY\n");
        return;
    }
    printf("Rear element: %d\n", q->arr[q->rear]);
}

int isEmptyD(CQueue *q) 
{
    return q->front == -1;
}

int isFullD(CQueue *q) 
{
    return ((q->rear + 1) % q->size == q->front);
}

void resizeQueue(CQueue *q) 
{
    int newSize = q->size * 2;
    int *newArr = (int *)malloc(sizeof(int) * newSize);

    int i = 0;
    int idx = q->front;
    if (!isEmptyD(q)) 
    {
        do {
            newArr[i++] = q->dynArr[idx];
            idx = (idx + 1) % q->size;
        } while (idx != (q->rear + 1) % q->size);
    }

    free(q->dynArr);
    q->dynArr = newArr;
    q->size = newSize;
    q->front = 0;
    q->rear = i - 1;

    printf("Dynamic queue resized to %d\n", newSize);
}

void enqueueD(CQueue *q, int val) 
{
    if (isFullD(q)) 
    {
        printf("Dynamic Circular Queue is full. Resizing...\n");
        resizeQueue(q);
    }
    if (isEmptyD(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->dynArr[q->rear] = val;
    printf("%d enqueued in dynamic circular queue\n", val);
}

void dequeueD(CQueue *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic queue EMPTY\n");
        return;
    }
    printf("Dequeued: %d\n", q->dynArr[q->front]);
    if (q->front == q->rear) 
        q->front = q->rear = -1;
    else 
        q->front = (q->front + 1) % q->size;
}

void displayD(CQueue *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Circular Queue is EMPTY\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) 
    {
        printf("%d ", q->dynArr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void peekFrontD(CQueue *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Circular Queue is EMPTY\n");
        return;
    }
    printf("Front element: %d\n", q->dynArr[q->front]);
}

void peekRearD(CQueue *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Circular Queue is EMPTY\n");
        return;
    }
    printf("Rear element: %d\n", q->dynArr[q->rear]);
}

int main() 
{
    CQueue q;
    int choice, op, val, size;

    q.front = q.rear = -1;
    q.dynArr = NULL;

    printf("Select queue type:\n1. Circular Queue using Static Memory Allocation\n2. Circular Queue using Dynamic Memory Allocation\n");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1: 
            q.size = MAX;
            while (1) {
                printf("\n--- Static Circular Queue Menu ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n6. Exit\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        enqueueS(&q, val);
                        break;
                    case 2:
                        dequeueS(&q);
                        break;
                    case 3:
                        displayS(&q);
                        break;
                    case 4:
                        peekFrontS(&q);
                        break;
                    case 5:
                        peekRearS(&q);
                        break;
                    case 6:
                        printf("Exiting static queue menu...\n");
                        break;
                    default:
                        printf("Invalid choice\n");
                        continue;
                }
                if (op == 6) break;
            }
            break;

        case 2: 
            printf("Enter initial size for dynamic queue: ");
            scanf("%d", &size);
            q.size = size;
            q.dynArr = (int *)malloc(sizeof(int) * size);

            while (1) {
                printf("\n--- Dynamic Circular Queue Menu ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n6. Exit\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        enqueueD(&q, val);
                        break;
                    case 2:
                        dequeueD(&q);
                        break;
                    case 3:
                        displayD(&q);
                        break;
                    case 4:
                        peekFrontD(&q);
                        break;
                    case 5:
                        peekRearD(&q);
                        break;
                    case 6:
                        printf("Exiting dynamic queue menu...\n");
                        break;
                    default:
                        printf("Invalid choice\n");
                        continue;
                }
                if (op == 6) break;
            }
            break;

        default:
            printf("Invalid queue type selected\n");
    }
    if (q.dynArr != NULL) free(q.dynArr);
    return 0;
}
