#include <stdio.h>
int a[20][20], n, indegree[20];

void topology()
{
    int i, j, u, v, s[20], t[20], top = -1, k = 0;
    for(j = 1; j <= n; j++)
    {
        indegree[j] = 0;
        for(i = 1; i <= n; i++)
            indegree[j] += a[i][j];
    }
    for(i = 1; i <= n; i++)
        if(indegree[i] == 0)
            s[++top] = i;
    while(top != -1)
    {
        u = s[top--];
        t[k++] = u;
        for(v = 1; v <= n; v++)
            if(a[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    s[++top] = v;
            }
    }
    if(k != n)
        printf("Graph contains a cycle\n");
    else
    {
        printf("Topological sequence:\n");
        for(i = 0; i < n; i++)
            printf("%d ", t[i]);
    }
}
int main()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    topology();
    return 0;
}
