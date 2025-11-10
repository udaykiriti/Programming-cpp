#include <stdio.h>

#include <stdlib.h>

#define MAXN 8

int N;

int sol[MAXN][MAXN];

int dx[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };

int dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

 

int isSafe(int x, int y) {

   return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);

}

 

int solveKTUtil(int x, int y, int moveCnt) {

   if (moveCnt == N * N)

       return 1;  // Completed tour

 

   for (int k = 0; k < 8; k++) {

       int nx = x + dx[k];

       int ny = y + dy[k];

       if (isSafe(nx, ny)) {

           sol[nx][ny] = moveCnt;

           if (solveKTUtil(nx, ny, moveCnt + 1))

               return 1;

           // backtrack

           sol[nx][ny] = -1;

       }

   }

   return 0;

}

 

void printSolution() {

   for (int i = 0; i < N; i++) {

       for (int j = 0; j < N; j++)

           printf("%d ", sol[i][j]);

       printf("\n");

   }

}

 

int main() {

   printf("Enter board size N: ");

   if (scanf("%d", &N) != 1 || N < 1 || N > MAXN) {

       printf("Invalid board size (1 to %d).\n", MAXN);

       return 1;

   }

 

   // initialize solution matrix

   for (int i = 0; i < N; i++)

       for (int j = 0; j < N; j++)

           sol[i][j] = -1;

 

   // starting position

   sol[0][0] = 0;

 

   if (solveKTUtil(0, 0, 1)) {

       printf("Knight’s tour solution:\n");

       printSolution();

   } else {

       printf("No solution exists.\n");

   }

   return 0;

}