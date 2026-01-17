/*
Problem: 263A - Beautiful Matrix
Link: https://codeforces.com/problemset/problem/263/A

Description:
You've got a 5x5 matrix that is filled with zeros and contains a single number one (1).
Your task is to perform a series of moves to bring the 1 to the center of the matrix (position (3,3) or (2,2) in 0-based indexing).
A move is defined as swapping two neighboring rows or two neighboring columns.

Input:
Five lines, each containing five integers (0 or 1). There is exactly one number one in the entire matrix.

Output:
Print the minimum number of moves needed to bring the 1 to the center.

Example:
Input:
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

Output:
0
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int arr[5][5], m = 0, n = 0;
  FOR(i, 0, 5)
  {
    FOR(j, 0, 5)
    {
      cin>>arr[i][j];
      if (arr[i][j] == 1)
      {
        m = i;
        n = j;
      }
    }
  }

  int moves = abs(m - 2) + abs(n - 2);
  cout<<moves<<endl;
  return 0;
}