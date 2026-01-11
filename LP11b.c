/* 11. b) Develop a menu driven program to implement Priority Queue with static and dynamic memory allocation 
mechanisms (Represent Queue using structure)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   

typedef struct
{
    int dataS[MAX];
    int prS[MAX];
    int *dataD;
    int *prD;

    int front, rear;
    int size;
} PQueue;

void initStatic(PQueue *q);
void initDynamic(PQueue *q);
int isEmpty(PQueue *q);
int isFull(PQueue *q);
void resizeQueue(PQueue *q);
void insert(PQueue *q, int item, int pr);
void delete(PQueue *q);
void peek(PQueue *q);
void display(PQueue *q);

void initStatic(PQueue *q)
{
    q->front = q->rear = -1;
    q->size = MAX;
    q->dataD = NULL;   
    q->prD = NULL;
}

void initDynamic(PQueue *q)
{
    int n;
    printf("Enter initial size: ");
    scanf("%d", &n);

    q->dataD = (int *)malloc(sizeof(int) * n);
    q->prD   = (int *)malloc(sizeof(int) * n);

    q->front = q->rear = -1;
    q->size = n;
}

int isEmpty(PQueue *q)
{
    return q->front == -1;
}

int isFull(PQueue *q)
{
    return q->rear == q->size - 1;
}

void resizeQueue(PQueue *q)
{
    int newSize = q->size * 2;

    q->dataD = (int *)realloc(q->dataD, sizeof(int) * newSize);
    q->prD   = (int *)realloc(q->prD, sizeof(int) * newSize);

    q->size = newSize;
    printf("Queue resized to %d\n", newSize);
}

void insert(PQueue *q, int item, int pr)
{
    if (isFull(q))
    {
        if (q->dataD != NULL)   
            resizeQueue(q);
        else
        {
            printf("Queue Overflow!\n");
            return;
        }
    }

    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        if (q->dataD != NULL)
        {
            q->dataD[0] = item;
            q->prD[0] = pr;
        }
        else
        {
            q->dataS[0] = item;
            q->prS[0] = pr;
        }
        return;
    }

    int i = q->rear;
    while (i >= q->front &&
          (q->dataD != NULL ? q->prD[i] : q->prS[i]) > pr)
    {
        if (q->dataD != NULL)
        {
            q->dataD[i + 1] = q->dataD[i];
            q->prD[i + 1] = q->prD[i];
        }
        else
        {
            q->dataS[i + 1] = q->dataS[i];
            q->prS[i + 1] = q->prS[i];
        }
        i--;
    }

    if (q->dataD != NULL)
    {
        q->dataD[i + 1] = item;
        q->prD[i + 1] = pr;
    }
    else
    {
        q->dataS[i + 1] = item;
        q->prS[i + 1] = pr;
    }

    q->rear++;
}

void delete(PQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
        return;
    }

    if (q->dataD != NULL)
        printf("Deleted: %d (Priority %d)\n", q->dataD[q->front], q->prD[q->front]);
    else
        printf("Deleted: %d (Priority %d)\n", q->dataS[q->front], q->prS[q->front]);

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
}

void peek(PQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    if (q->dataD != NULL)
        printf("Peek: %d (Priority %d)\n", q->dataD[q->front], q->prD[q->front]);
    else
        printf("Peek: %d (Priority %d)\n", q->dataS[q->front], q->prS[q->front]);
}

void display(PQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->dataD != NULL)
            printf("%d(P=%d)  ", q->dataD[i], q->prD[i]);
        else
            printf("%d(P=%d)  ", q->dataS[i], q->prS[i]);
    }
    printf("\n");
}

int main()
{
    PQueue q;
    int ch, item, pr, type;

    printf("PRIORITY QUEUE\n");
    printf("1. Static Memory Allocation\n");
    printf("2. Dynamic Memory Allocation\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    if (type == 1)
        initStatic(&q);
    else
        initDynamic(&q);

    do
    {
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element and priority: ");
            scanf("%d %d", &item, &pr);
            insert(&q, item, pr);
            break;
        case 2:
            delete(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            display(&q);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (ch != 5);

    if (q.dataD != NULL)
    {
        free(q.dataD);
        free(q.prD);
    }

    return 0;
}