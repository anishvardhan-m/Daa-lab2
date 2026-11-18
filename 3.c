#include <stdio.h>
#include <limits.h>
#define MAX 12
#define INF (LLONG_MAX / 4)
long long cost[MAX][MAX], dp[1 << MAX][MAX];
int n;

long long tsp(int mask, int pos)
{
    int city;
    long long ans = INF, value;
    if(mask == (1 << n) - 1)
        return cost[pos][0];
    if(dp[mask][pos] != -1)
        return dp[mask][pos];
    for(city = 0; city < n; city++)
        if(!(mask & (1 << city)))
        {
            value = cost[pos][city] + tsp(mask | (1 << city), city);
            if(value < ans) ans = value;
        }
    return dp[mask][pos] = ans;
}

int main()
{
    int i, j, mask;
    printf("Enter number of cities (2 to 12): ");
    scanf("%d", &n);
    if(n < 2 || n > MAX) return 1;
    printf("Enter complete cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%lld", &cost[i][j]);
            if(cost[i][j] < 0 || cost[i][j] > 1000000000) return 1;
        }
    for(mask = 0; mask < (1 << n); mask++)
        for(i = 0; i < n; i++)
            dp[mask][i] = -1;
    printf("Minimum tour cost = %lld\n", tsp(1, 0));
    return 0;
}
