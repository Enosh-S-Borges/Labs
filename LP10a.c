/* 10.a) Develop a menu driven program to implement ordinary Queue with static and 
dynamic memory allocation mechanisms. (Represent Queue using structure). */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

struct Queue
{
    int arr[MAX];   
    int *data;    
    int front, rear;
    int size;      
};

int isEmpty(struct Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void initStatic(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFullStatic(struct Queue *q)
{
    return q->rear == MAX - 1;
}

void enqueueStatic(struct Queue *q, int item)
{
    if (isFullStatic(q))
    {
        printf("Static Queue is Full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = item;
    printf("Inserted: %d\n", item);
}

void dequeueStatic(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Static Queue is Empty\n");
        return;
    }
    printf("Deleted: %d\n", q->arr[q->front++]);
}

void peekFrontStatic(struct Queue *q)
{
    if (isEmpty(q))
        printf("Static Queue is Empty\n");
    else
        printf("Front element: %d\n", q->arr[q->front]);
}

void peekRearStatic(struct Queue *q)
{
    if (isEmpty(q))
        printf("Static Queue is Empty\n");
    else
        printf("Rear element: %d\n", q->arr[q->rear]);
}

void displayStatic(struct Queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Static Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}


void initDynamic(struct Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->data = (int *)malloc(size * sizeof(int));
}

void resizeQueue(struct Queue *q)
{
    int newSize = q->size * 2;
    int *temp = (int *)realloc(q->data, newSize * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed\n");
        return;
    }

    q->data = temp;
    q->size = newSize;
    printf("Queue resized. New size = %d\n", q->size);
}

void enqueueDynamic(struct Queue *q, int item)
{
    if (q->rear == q->size - 1)
        resizeQueue(q);

    if (q->front == -1)
        q->front = 0;

    q->data[++q->rear] = item;
    printf("Inserted: %d\n", item);
}

void dequeueDynamic(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Dynamic Queue is Empty\n");
        return;
    }
    printf("Deleted: %d\n", q->data[q->front++]);
}

void peekFrontDynamic(struct Queue *q)
{
    if (isEmpty(q))
        printf("Dynamic Queue is Empty\n");
    else
        printf("Front element: %d\n", q->data[q->front]);
}

void peekRearDynamic(struct Queue *q)
{
    if (isEmpty(q))
        printf("Dynamic Queue is Empty\n");
    else
        printf("Rear element: %d\n", q->data[q->rear]);
}

void displayDynamic(struct Queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Dynamic Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}

int main()
{
    struct Queue q;
    int mainChoice, choice, item, size;

    printf("===== ORDINARY QUEUE =====\n");
    printf("1. Static Memory Allocation (SMA)\n");
    printf("2. Dynamic Memory Allocation (DMA)\n");
    printf("Enter choice: ");
    scanf("%d", &mainChoice);

    if (mainChoice == 1)
    {
        initStatic(&q);
        do
        {
            printf("\n--- Static Queue Menu ---\n");
            printf("1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Peek Rear\n5.Display\n6.Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1: scanf("%d", &item); enqueueStatic(&q, item); break;
                case 2: dequeueStatic(&q); break;
                case 3: peekFrontStatic(&q); break;
                case 4: peekRearStatic(&q); break;
                case 5: displayStatic(&q); break;
            }
        } while (choice != 6);
    }
    else if (mainChoice == 2)
    {
        printf("Enter initial queue size: ");
        scanf("%d", &size);
        initDynamic(&q, size);

        do
        {
            printf("\n--- Dynamic Queue Menu ---\n");
            printf("1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Peek Rear\n5.Display\n6.Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1: scanf("%d", &item); enqueueDynamic(&q, item); break;
                case 2: dequeueDynamic(&q); break;
                case 3: peekFrontDynamic(&q); break;
                case 4: peekRearDynamic(&q); break;
                case 5: displayDynamic(&q); break;
                case 6: free(q.data); break;
            }
        } while (choice != 6);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}