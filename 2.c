#include <stdio.h>
#define INF 99999
int main()
{
    int p[20][20], n, i, j, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if(n < 1 || n >= 20) return 1;
    printf("Enter cost matrix (99999 for no edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(p[i][k] != INF && p[k][j] != INF &&
                   p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];
    printf("All-pairs shortest distances:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            if(p[i][j] == INF) printf("INF ");
            else printf("%d ", p[i][j]);
        printf("\n");
    }
    return 0;
}
