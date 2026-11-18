#include <stdio.h>
#define MAX 20
int a[MAX][MAX], path[MAX], n;

int safe(int vertex, int pos)
{
    int i;
    if(!a[path[pos - 1]][vertex]) return 0;
    for(i = 1; i < pos; i++)
        if(path[i] == vertex) return 0;
    return 1;
}

int hamiltonian(int pos)
{
    int vertex;
    if(pos > n)
        return a[path[n]][path[1]] != 0;
    for(vertex = 2; vertex <= n; vertex++)
        if(safe(vertex, pos))
        {
            path[pos] = vertex;
            if(hamiltonian(pos + 1)) return 1;
            path[pos] = 0;
        }
    return 0;
}

int main()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    if(n < 3 || n >= MAX) return 1;
    printf("Enter adjacency matrix of undirected graph:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    path[1] = 1;
    if(hamiltonian(2))
    {
        printf("Hamiltonian cycle: ");
        for(i = 1; i <= n; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[1]);
    }
    else
        printf("No Hamiltonian cycle\n");
    return 0;
}
