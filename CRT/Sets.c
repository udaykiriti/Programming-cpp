/*
#include<stdio.h>
#include<stdlib.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define SIZE 6

int main(){
  int parent[SIZE];
  FOR(i, SIZE) parent[i] = i; 
  printf("Parent array initialized: ");
  FOR(i, SIZE) printf("%d ", parent[i]);
  return 0;
}
  */

/*
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define FOR(i, n) for(int i = 0; i < n; i++)
int parent[SIZE];
#define EXIT return 0

int find(int x){
  if(parent[x]==x) return x;
  return find(parent[x]);
}

void union_sets(int a,int b){
  int rootA = find(a);
  int rootB = find(b);
  if(rootA != rootB)  parent[rootB] = rootA; 
}

int main(void){
  FOR(i, SIZE) parent[i] = i; 
  union_sets(0, 1);
  union_sets(2,3);
  union_sets(1, 2);

  FOR(i, SIZE) printf("Element %d -> %d\n", i, find(i));
  EXIT;
}
*/

#include <stdio.h>
#define SIZE 6
#define FOR(i, n) for(int i = 0; i < n; i++)
int parent[SIZE];

int find(int x) {
    if (parent[x] != x)
        return find(parent[x]);
    return x;
}

void union_sets(int a, int b, int (*find_func)(int)) {
    int rootA = find_func(a);
    int rootB = find_func(b);
    if (rootA != rootB) parent[rootB] = rootA;
}

void print_parents(const char* msg) {
    printf("%s: ", msg);
    FOR(i, SIZE) printf("%d ", parent[i]);
    printf("\n");
}

int main(void) {
    FOR(i, SIZE) parent[i] = i;
    // union_sets(0, 1, find);
    // union_sets(2, 3, find);
    // union_sets(1, 2, find);

    // print_parents("Parent array after unions (no compression)");
    // FOR(i, SIZE) find(i);
    // print_parents("Parent array after finds (no compression)");

    // FOR(i, SIZE) parent[i] = i;
    // union_sets(0, 1, find);
    // union_sets(2, 3, find);
    // union_sets(1, 2, find);

    // print_parents("Parent array after unions (reset, no compression)");
    // FOR(i, SIZE) find(i);
    // print_parents("Parent array after finds (reset, no compression)");
    

    return 0;
}