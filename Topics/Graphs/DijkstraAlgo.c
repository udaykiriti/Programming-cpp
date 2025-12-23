#include<stdio.h>
#define MAX 100
#define INF 99999

void dijkstra(int graph[MAX][MAX], int v, int start) {
    int dist[MAX], visited[MAX], i, j;
    
    for (i = 0; i < v; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[start] = 0;

    for (i = 0; i < v - 1; i++) {
        int min = INF, min_index;
        
        for (j = 0; j < v; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                min_index = j;
            }
        }
        
        visited[min_index] = 1;

        for (j = 0; j < v; j++) {
            if (!visited[j] && graph[min_index][j] && dist[min_index] != INF &&
                dist[min_index] + graph[min_index][j] < dist[j]) {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (i = 0; i < v; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


int main(){
  int i,j,v,start;
  int graph[MAX][MAX];
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  printf("Enter the weight");
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      scanf("%d", &graph[i][j]);
    }
  }
  printf("Enter the starting vertex: ");
  scanf("%d", &start);
  dijkstra(graph, v, start);
  return 0;
}