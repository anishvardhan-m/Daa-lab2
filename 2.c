#include <stdio.h>
#define INF 99999
int main()
{
    int cost[20][20], dist[20], visited[20] = {0};
    int n, v, i, j, u, min, count;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 for no edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    printf("Enter source vertex: ");
    scanf("%d", &v);
    for(i = 1; i <= n; i++)
        dist[i] = cost[v][i];
    dist[v] = 0;
    visited[v] = 1;
    for(count = 1; count < n; count++)
    {
        min = INF;
        u = -1;
        for(i = 1; i <= n; i++)
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        if(u == -1) break;
        visited[u] = 1;
        for(i = 1; i <= n; i++)
            if(!visited[i] && dist[u] + cost[u][i] < dist[i])
                dist[i] = dist[u] + cost[u][i];
    }
    printf("Shortest distances:\n");
    for(i = 1; i <= n; i++)
        if(i != v)
        {
            if(dist[i] == INF) printf("%d -> %d: unreachable\n", v, i);
            else printf("%d -> %d: %d\n", v, i, dist[i]);
        }
    return 0;
}
