/*11.b. Using Method 1 - Develop a menu driven program to implement Priority Queue with static and 
dynamic memory allocation mechanisms (Represent Queue using structure) */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int *data;
    int arr[MAX];
    int size;
    int capacity;
} PriorityQueue;

void initStatic(PriorityQueue *pq)
{
    pq->data = pq->arr;
    pq->capacity = MAX;
    pq->size = 0;
}

void initDynamic(PriorityQueue *pq)
{
    pq->capacity = MAX;
    pq->size = 0;
    pq->data = (int *)malloc(pq->capacity * sizeof(int));
}

int isEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

void insert(PriorityQueue *pq, int value, int isDynamic)
{
    if (pq->size == pq->capacity)
    {
        if (isDynamic)
        {
            pq->capacity *= 2;
            pq->data = (int *)realloc(pq->data, pq->capacity * sizeof(int));
        }
        else
        {
            printf("Priority Queue is FULL (Static)\n");
            return;
        }
    }

    pq->data[pq->size++] = value;
}

void deleteMax(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < pq->size; i++)
        if (pq->data[i] > pq->data[maxIndex])
            maxIndex = i;

    printf("Deleted element: %d\n", pq->data[maxIndex]);

    for (int i = maxIndex; i < pq->size - 1; i++)
        pq->data[i] = pq->data[i + 1];

    pq->size--;
}

void display(PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->data[i]);

    printf("\n");
}

int main()
{
    PriorityQueue pq;
    int choice, value, mode;

    printf("Select Memory Allocation Method\n");
    printf("1. Static\n");
    printf("2. Dynamic\n");
    printf("Enter choice: ");
    scanf("%d", &mode);

    if (mode == 1)
        initStatic(&pq);
    else
        initDynamic(&pq);

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete Maximum");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(&pq, value, mode == 2);
            break;

        case 2:
            deleteMax(&pq);
            break;

        case 3:
            display(&pq);
            break;

        case 4:
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    if (mode == 2)
        free(pq.data);

    return 0;
}