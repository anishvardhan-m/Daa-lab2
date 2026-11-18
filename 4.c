#include <stdio.h>
#include <stdlib.h>
int x[20], count = 0;
int place(int k, int i)
{
    int j;
    for(j = 1; j < k; j++)
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    return 1;
}
void print_sol(int n)
{
    int i, j;
    printf("\nSolution %d:\n", ++count);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf(x[i] == j ? "Q " : "* ");
        printf("\n");
    }
}
void queen(int k, int n)
{
    int i;
    for(i = 1; i <= n; i++)
        if(place(k, i))
        {
            x[k] = i;
            if(k == n) print_sol(n);
            else queen(k + 1, n);
        }
}
int main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1, n);
    printf("\nTotal solutions = %d\n", count);
    return 0;
}
