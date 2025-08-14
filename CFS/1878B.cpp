/* Problem: Filling the Grid
You are given `t` test cases. For each test case, you are given an integer `n`. You need to generate a sequence of `n` integers such that:
1. The sequence starts from 3.
2. Each number in the sequence is incremented by 1.
3. If the next number is divisible by 3, skip it.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 100) — the number of test cases.
Each of the next `t` lines contains a single integer `n` (1 ≤ n ≤ 100).

Output:
For each test case, print the sequence of `n` integers on a new line.

Example:
Input:
2
5
3
Output:
3 4 6 7 9
3 4 6
*/

#include <bits/stdc++.h>
using namespace std;
#define BYE return 0;
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
  int n; cin >> n;
  int current = 3;
  FOR(i, 0, n){
    while (current % 3 == 0)
      current++;
    cout << current << ' ';
    current++;
  }
  cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  BYE;
}