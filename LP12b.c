/* 12.b) Develop a menu driven program to implement Graph traversal techniques. */
#include <stdio.h>

#define MAX 4

int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int choice, start, i, j;

    while (1)
    {
        printf("\n\n===== GRAPH TRAVERSAL MENU =====");
        printf("\n1. Create Graph");
        printf("\n2. Depth First Search (DFS)");
        printf("\n3. Breadth First Search (BFS)");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number of vertices: ");
            scanf("%d", &n);

            printf("Enter adjacency matrix:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            break;

        case 2:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &start);
            for (i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS Traversal: ");
            DFS(start);
            break;

        case 3:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &start);
            printf("BFS Traversal: ");
            BFS(start);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice!");
        }
    }
}