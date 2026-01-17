/* Problem: Filling the Grid
You are given a grid of size `n × n`. Your task is to fill the grid in such a way that each row and each column contains exactly one number from 1 to n.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 100) — the number of test cases.
Each of the next `t` lines contains a single integer `n` (1 ≤ n ≤ 100) — the size of the grid.

Output:
For each test case, print the integer `n` on a new line.

Example:
Input:
3
1
2
3
Output:
1
2
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << n << '\n';
  }
}