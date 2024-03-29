#include <stdio.h>

int n, v, visited[100];
int adj[100][100];

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for(int i=0; i<n; i++)
        if(adj[v][i] && !visited[i])
            dfs(i);
}

int dfsPossible() {
    for(int i=0; i<n; i++)
        if(!visited[i])
            return 0;
    return 1;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        visited[i] = 0;
    
    printf("Enter adjacency matrix: \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &adj[i][j]);
    
    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    printf("DFS traversal: \n");
    dfs(v);

    if(!dfsPossible)
        printf("DFS is not possible, all the nodes are not reachable");    
    return 0;
}

/*
0 1 0 1 1 0 0
1 0 1 0 1 0 0
0 1 0 0 1 1 1
1 0 0 0 1 0 0
1 1 1 1 0 1 0
0 0 1 0 1 0 1
0 0 1 0 0 1 0

0 1 0 1 0 0 0
1 0 1 1 0 1 1
0 1 0 1 1 1 0
1 1 1 0 1 0 0
0 0 1 1 0 0 0
0 1 1 0 0 0 0
0 1 0 0 0 0 0
*/