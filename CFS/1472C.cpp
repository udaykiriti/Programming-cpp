/* Problem: Fair Division
You are given `t` test cases. For each test case, you are given an integer `n` (the number of candies) and an array of integers representing the candies. Each candy is either of weight `1` or `2`. Your task is to determine if it is possible to divide the candies into two groups such that:
1. The total weight of candies in both groups is the same.
2. Each group contains at least one candy.

Input:
The first line contains a single integer `t` (1 ≤ t ≤ 1000) — the number of test cases.
For each test case:
- The first line contains an integer `n` (1 ≤ n ≤ 100) — the number of candies.
- The second line contains `n` integers, each being `1` or `2`.

Output:
For each test case, print "YES" if it is possible to divide the candies as described, otherwise print "NO".

Example:
Input:
3
4
1 1 1 1
4
2 2 2 2
3
1 1 2
Output:
YES
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;
#define optimize()              \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define fraction()              \
  cout.unsetf(ios::floatfield); \
  cout.precision(10);           \
  cout.setf(ios::fixed, ios::floatfield);
int main()
{
  optimize();
  int t; cin >> t;
  while (t--)
  {
    int n, i; cin >> n;
    int a[n];
    vector<int> dp(n);
    for (auto &u : a)
      cin >> u;
    for (i = n - 1; i >= 0; i--)
    {
      dp[i] = a[i];
      int j = i + a[i];
      if (j < n)
        dp[i] += dp[j];
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
  return 0;
}