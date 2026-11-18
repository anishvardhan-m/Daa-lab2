#include <stdio.h>
#define INF 99999
#define MAX 12
int cost[MAX][MAX], dp[1 << MAX][MAX], n;
int tsp(int mask, int pos)
{
    int city, ans = INF, val;
    if(mask == (1 << n) - 1)
        return cost[pos][0];
    if(dp[mask][pos] != -1)
        return dp[mask][pos];
    for(city = 0; city < n; city++)
        if(!(mask & (1 << city)))
        {
            val = cost[pos][city] + tsp(mask | (1 << city), city);
            if(val < ans) ans = val;
        }
    return dp[mask][pos] = ans;
}
int main()
{
    int i, j, mask;
    printf("Enter number of cities (2 to 11): ");
    scanf("%d", &n);
    if(n < 2 || n >= MAX) return 1;
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for(mask = 0; mask < (1 << n); mask++)
        for(i = 0; i < n; i++)
            dp[mask][i] = -1;
    printf("Minimum tour cost = %d\n", tsp(1, 0));
    return 0;
}
