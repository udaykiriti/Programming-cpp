#include <iostream>
using namespace std;

int main()
{
  int rowsA, colsA, rowsB, colsB;
  cin >> rowsA >> colsA;
  int A[rowsA][colsA];
  for (int i = 0; i < rowsA; i++)
    for (int j = 0; j < colsA; j++)
      cin >> A[i][j];

  cin >> rowsB >> colsB;
  int B[rowsB][colsB];
  for (int i = 0; i < rowsB; i++)
    for (int j = 0; j < colsB; j++)
      cin >> B[i][j];

  if (colsA != rowsB)
  {
    cout << "Invalid dimensions for multiplication." << endl;
    return 1;
  }

  int C[rowsA][colsB] = {0};
  for (int i = 0; i < rowsA; i++)
    for (int j = 0; j < colsB; j++)
      for (int k = 0; k < colsA; k++)
        C[i][j] += A[i][k] * B[k][j];

  for (int i = 0; i < rowsA; i++)
  {
    for (int j = 0; j < colsB; j++)
      cout << C[i][j] << " ";
    cout << endl;
  }

  return 0;
}
