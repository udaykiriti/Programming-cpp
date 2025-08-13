#include <stdio.h>

#include <stdlib.h>

 

#define MAXN 10

 

int board[MAXN][MAXN];

int N;

int solutionCount = 0;

 

int isSafe(int row, int col) {

   // Check this column on upper side

   for (int i = 0; i < row; i++)

       if (board[i][col])

           return 0;

 

   // Check upper left diagonal

   for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)

       if (board[i][j])

           return 0;

 

   // Check upper right diagonal

   for (int i = row, j = col; i >= 0 && j < N; i--, j++)

       if (board[i][j])

           return 0;

 

   return 1;

}

 

void printBoard() {

   printf("Solution %d:\n", ++solutionCount);

   for (int i = 0; i < N; i++) {

       for (int j = 0; j < N; j++)

           printf("%c ", board[i][j] ? 'Q' : '.');

       printf("\n");

   }

   printf("\n");

}

 

void solveNQueens(int row) {

   if (row == N) {

       printBoard();

       return;

   }

 

   for (int col = 0; col < N; col++) {

if(isSafe(row,col))

{

           board[row][col] = 1;

           solveNQueens(row + 1);

}

           board[row][col] = 0; // backtrack

       }

   }

 

 

int main() {

   printf("Enter the value of N: ");

   scanf("%d", &N);

 

 if (N < 1 || N > MAXN) {

       printf("Invalid input. Please enter N between 1 and %d.\n", MAXN);

       return 1;

   }

 

   solveNQueens(0);

 

   if (solutionCount == 0)

       printf("No solution exists.\n");

 

   return 0;

}