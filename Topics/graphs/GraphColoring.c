#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)

int grid[MAX][MAX] = {0};  
int color[MAX] = {0};   
int n, m;                 

int isSafe(int v, int c) {
    FOR(i, 0, n) {
        if (grid[v][i] && color[i] == c)  return 0;
    }
    return 1;
}

int isSolve(int v) {
    if (v == n)
        return 1;

    FORE(c, 1, m) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (isSolve(v + 1))
                return 1;
            color[v] = 0;
        }
    }

    return 0;
}

int main() {
    int e;
    scanf("%d %d", &n, &m); 
    scanf("%d", &e);        
    FOR(i, 0, e) {
        int u, v;
        scanf("%d %d", &u, &v);
        grid[u][v] = grid[v][u] = 1;
    }
    if (isSolve(0)) printf("1\n");
    else printf("0\n");
    return 0;
}
/*
input:
4 3
5
0 1
0 2
1 2
1 3
2 3

output:
1

input:
5 2
4
0 1
1 2
2 3
3 4
output:
1

*/