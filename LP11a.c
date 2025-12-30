/* 11.a) Develop a menu driven program to implement Double Ended Queue with static and 
dynamic memory allocation mechanisms. (Represent Queue using structure)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct 
{
    int arr[MAX];      
    int *dynArr;       
    int front, rear;
    int size;
} Deque;


int isEmptyS(Deque *q) 
{
    return q->front == -1;
}

int isFullS(Deque *q) 
{
    return ((q->rear + 1) % MAX == q->front);
}

void insertFrontS(Deque *q, int val) 
{
    if (isFullS(q)) 
    {
        printf("Static Deque is FULL. Cannot insert %d at front.\n", val);
        return;
    }
    if (isEmptyS(q)) 
    {
        q->front = q->rear = 0;
    } 
    else 
    {
        q->front = (q->front - 1 + MAX) % MAX;
    }
    q->arr[q->front] = val;
    printf("%d inserted at front.\n", val);
}

void insertRearS(Deque *q, int val) 
{
    if (isFullS(q)) 
    {
        printf("Static Deque is FULL. Cannot insert %d at rear.\n", val);
        return;
    }
    if (isEmptyS(q)) 
    {
        q->front = q->rear = 0;
    } 
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = val;
    printf("%d inserted at rear.\n", val);
}

void deleteFrontS(Deque *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Deque is EMPTY.\n");
        return;
    }
    printf("Deleted from front: %d\n", q->arr[q->front]);
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->front = (q->front + 1) % MAX;
    }
}

void deleteRearS(Deque *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Deque is EMPTY.\n");
        return;
    }
    printf("Deleted from rear: %d\n", q->arr[q->rear]);
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->rear = (q->rear - 1 + MAX) % MAX;
    }
}

void displayS(Deque *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Deque is EMPTY.\n");
        return;
    }
    printf("Deque elements: ");
    int i = q->front;
    while (1) 
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void peekFrontS(Deque *q) 
{
    if (isEmptyS(q)) 
    {
        printf("Static Deque is EMPTY.\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void peekRearS(Deque *q)
{
    if (isEmptyS(q)) 
    {
        printf("Static Deque is EMPTY.\n");
        return;
    }
    printf("Rear element: %d\n", q->arr[q->rear]);
}

int isEmptyD(Deque *q) 
{
    return q->front == -1;
}

int isFullD(Deque *q) 
{
    return ((q->rear + 1) % q->size == q->front);
}

void resizeDeque(Deque *q) 
{
    int newSize = q->size * 2;
    int *newArr = (int *)malloc(sizeof(int) * newSize);
    int i = 0, idx = q->front;
    if (!isEmptyD(q)) 
    {
        do 
        {
            newArr[i++] = q->dynArr[idx];
            idx = (idx + 1) % q->size;
        } while (idx != (q->rear + 1) % q->size);
    }
    free(q->dynArr);
    q->dynArr = newArr;
    q->size = newSize;
    q->front = 0;
    q->rear = i - 1;
    printf("Dynamic deque resized to %d\n", newSize);
}

void insertFrontD(Deque *q, int val) 
{
    if (isFullD(q)) 
    {
        printf("Dynamic Deque is full. Resizing...\n");
        resizeDeque(q);
    }
    if (isEmptyD(q)) 
    {
        q->front = q->rear = 0;
    } 
    else 
    {
        q->front = (q->front - 1 + q->size) % q->size;
    }
    q->dynArr[q->front] = val;
    printf("%d inserted at front.\n", val);
}

void insertRearD(Deque *q, int val) 
{
    if (isFullD(q)) 
    {
        printf("Dynamic Deque is full. Resizing...\n");
        resizeDeque(q);
    }
    if (isEmptyD(q)) 
    {
        q->front = q->rear = 0;
    } 
    else 
    {
        q->rear = (q->rear + 1) % q->size;
    }
    q->dynArr[q->rear] = val;
    printf("%d inserted at rear.\n", val);
}

void deleteFrontD(Deque *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Deque is EMPTY.\n");
        return;
    }
    printf("Deleted from front: %d\n", q->dynArr[q->front]);
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->front = (q->front + 1) % q->size;
    }
}

void deleteRearD(Deque *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Deque is EMPTY.\n");
        return;
    }
    printf("Deleted from rear: %d\n", q->dynArr[q->rear]);
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->rear = (q->rear - 1 + q->size) % q->size;
    }
}

void displayD(Deque *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Deque is EMPTY.\n");
        return;
    }
    printf("Deque elements: ");
    int i = q->front;
    while (1) 
    {
        printf("%d ", q->dynArr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void peekFrontD(Deque *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Deque is EMPTY.\n");
        return;
    }
    printf("Front element: %d\n", q->dynArr[q->front]);
}

void peekRearD(Deque *q) 
{
    if (isEmptyD(q)) 
    {
        printf("Dynamic Deque is EMPTY.\n");
        return;
    }
    printf("Rear element: %d\n", q->dynArr[q->rear]);
}

int main() 
{
    Deque dq;
    dq.front = dq.rear = -1;
    dq.dynArr = NULL;
    int choice, op, val, size;

    printf("Select deque type:\n1. Static Deque\n2. Dynamic Deque\n");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1:
            dq.size = MAX;
            while(1) 
            {
                printf("\n--- Static Deque Menu ---\n");
                printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n");
                printf("5. Display\n6. Peek Front\n7. Peek Rear\n8. Exit\n");
                scanf("%d", &op);

                switch(op) 
                {
                    case 1: printf("Enter value: "); scanf("%d", &val); insertFrontS(&dq, val); break;
                    case 2: printf("Enter value: "); scanf("%d", &val); insertRearS(&dq, val); break;
                    case 3: deleteFrontS(&dq); break;
                    case 4: deleteRearS(&dq); break;
                    case 5: displayS(&dq); break;
                    case 6: peekFrontS(&dq); break;
                    case 7: peekRearS(&dq); break;
                    case 8: printf("Exiting Static Deque Menu...\n"); break;
                    default: printf("Invalid choice.\n"); continue;
                }
                if(op == 8) break;
            }
            break;

        case 2:
            printf("Enter initial size for dynamic deque: ");
            scanf("%d", &size);
            dq.size = size;
            dq.dynArr = (int *)malloc(sizeof(int) * size);

            while(1) 
            {
                printf("\n--- Dynamic Deque Menu ---\n");
                printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n");
                printf("5. Display\n6. Peek Front\n7. Peek Rear\n8. Exit\n");
                scanf("%d", &op);

                switch(op) 
                {
                    case 1: printf("Enter value: "); scanf("%d", &val); insertFrontD(&dq, val); break;
                    case 2: printf("Enter value: "); scanf("%d", &val); insertRearD(&dq, val); break;
                    case 3: deleteFrontD(&dq); break;
                    case 4: deleteRearD(&dq); break;
                    case 5: displayD(&dq); break;
                    case 6: peekFrontD(&dq); break;
                    case 7: peekRearD(&dq); break;
                    case 8: printf("Exiting Dynamic Deque Menu...\n"); break;
                    default: printf("Invalid choice.\n"); continue;
                }
                if(op == 8) break;
            }

            if(dq.dynArr != NULL) free(dq.dynArr);
            break;

        default:
            printf("Invalid deque type selected.\n");
    }
    return 0;
}