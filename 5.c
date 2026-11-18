#include <stdio.h>
#define MAX 20
int a[MAX][MAX], color[MAX], n, m, count = 0;

int safe(int vertex, int c)
{
    int i;
    if(a[vertex][vertex]) return 0;
    for(i = 1; i <= n; i++)
        if(a[vertex][i] && color[i] == c)
            return 0;
    return 1;
}

void coloring(int vertex)
{
    int c, i;
    if(vertex > n)
    {
        printf("Solution %d: ", ++count);
        for(i = 1; i <= n; i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }
    for(c = 1; c <= m; c++)
        if(safe(vertex, c))
        {
            color[vertex] = c;
            coloring(vertex + 1);
            color[vertex] = 0;
        }
}

int main()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if(n < 1 || n >= MAX) return 1;
    printf("Enter adjacency matrix of undirected graph:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter number of colours: ");
    scanf("%d", &m);
    if(m < 1 || m >= MAX) return 1;
    coloring(1);
    if(count == 0) printf("No colouring possible\n");
    printf("Total solutions = %d\n", count);
    return 0;
}
