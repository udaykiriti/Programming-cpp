#include<stdio.h>
#include<stdlib.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)

int isSafe(int graph[][20], int path[], int pos, int v, int n) {
    if (graph[path[pos - 1]][v] == 0) return 0; 
    FOR(i, 0, pos) {
        if (path[i] == v) return 0; 
    }
    return 1;
}

void HamiltonianCycle(int graph[][20], int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) { 
            printf("Hamiltonian Cycle: ");
            FOR(i, 0, n) {
                printf("%d ", path[i]);
            }
            printf("%d\n", path[0]); 
        }
        return;
    }
    FOR(v, 1, n) {
        if (isSafe(graph, path, pos, v, n)) {
            path[pos] = v;
            HamiltonianCycle(graph, path, pos + 1, n);
            path[pos] = -1; 
        }
    }
}

int main() {
    int n, graph[20][20], path[20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);  
    printf("Enter adjacency matrix:\n");
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            scanf("%d", &graph[i][j]);
        }
    }
    FOR(i, 0, n)
        path[i] = -1;
    path[0] = 0; 
    HamiltonianCycle(graph, path, 1, n);
    return 0;
}
