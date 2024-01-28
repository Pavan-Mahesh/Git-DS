#include <stdio.h>

int n, v, visited[100], queue[100], front = -1, rear = -1;
int adj[100][100];

void bfs(int v) {
    printf("%d ", v);
    for(int i=0; i<n; i++){
        if(adj[v][i] && !visited[i]){
            queue[++rear] = i;
            visited[i] = 1;
        }
    }
    if(front < rear) {
        front++;
        bfs(queue[front]);
    }
}

int bfsPossible() {
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
    queue[0] = v;
    rear = front = 0;
    visited[v] = 1;

    printf("BFS traversal: \n");
    bfs(v);

    if(!bfsPossible)
        printf("BFS is not possible, all the nodes are not reachable");
    
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