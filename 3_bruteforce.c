#include <stdio.h>
#include <limits.h>
#define MAX 10
long long cost[MAX][MAX], best = LLONG_MAX;
int n, visited[MAX];

void tsp(int pos, int count, long long total)
{
    int city;
    if(count == n)
    {
        total += cost[pos][0];
        if(total < best) best = total;
        return;
    }
    for(city = 1; city < n; city++)
        if(!visited[city])
        {
            visited[city] = 1;
            tsp(city, count + 1, total + cost[pos][city]);
            visited[city] = 0;
        }
}

int main()
{
    int i, j;
    printf("Enter number of cities (2 to 10): ");
    scanf("%d", &n);
    if(n < 2 || n > MAX) return 1;
    printf("Enter complete cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%lld", &cost[i][j]);
            if(cost[i][j] < 0 || cost[i][j] > 1000000000) return 1;
        }
    visited[0] = 1;
    tsp(0, 1, 0);
    printf("Minimum tour cost = %lld\n", best);
    return 0;
}
