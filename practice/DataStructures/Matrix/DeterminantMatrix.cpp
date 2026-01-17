#include <iostream>
#include <vector>
using namespace std;

int determinant(vector<vector<int>> matrix, int n)
{
  if (n == 1)
    return matrix[0][0];
  if (n == 2)
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

  int det = 0;
  for (int p = 0; p < n; p++)
  {
    vector<vector<int>> subMatrix(n - 1, vector<int>(n - 1));
    for (int i = 1; i < n; i++)
    {
      int colIdx = 0;
      for (int j = 0; j < n; j++)
      {
        if (j == p)
          continue;
        subMatrix[i - 1][colIdx] = matrix[i][j];
        colIdx++;
      }
    }
    det += matrix[0][p] * determinant(subMatrix, n - 1) * (p % 2 == 0 ? 1 : -1);
  }
  return det;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];

  int result = determinant(matrix, n);
  cout << "Determinant: " << result << endl;
  return 0;
}
