// Solution File: 2037A.cpp
// Author: kiriti__ (Codeforces ID)
// GitHub: https://github.com/udaykiriti/codeforces-solutions-master

/*
Problem: 2037A - Twice (Codeforces Round 988 Div. 3)

Description:
------------
Kinich receives an array of integers and wants to maximize his score by performing
a specific operation as many times as possible.

Operation:
- Select two indices i and j (1 ≤ i < j ≤ n) such that:
  * Neither i nor j has been used in any previous operation.
  * a[i] == a[j]
- Increase the score by 1 for each such valid operation.

Goal:
- Find the maximum score Kinich can achieve by performing the operation
  as many times as possible on disjoint (non-overlapping) pairs with equal values.

Input:
------
- The first line contains an integer t (1 ≤ t ≤ 500) — the number of test cases.
- For each test case:
  * An integer n (1 ≤ n ≤ 20) — the size of the array.
  * A line of n integers (1 ≤ a[i] ≤ n) — the elements of the array.

Output:
-------
- For each test case, output a single integer — the maximum score possible.

Example:
--------
Input:
5
1
1
2
2 2
2
1 2
4
1 2 3 1
6
1 2 3 1 2 3

Output:
0
1
0
1
3

Explanation:
------------
- Count the frequency of each number in the array.
- For each number, the number of disjoint pairs that can be formed is floor(count / 2).
- Sum all such pairs for the final score.
*/

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define EXIT return 0
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
  int n; cin>>n;
  map<int, int> freq;
  FOR(i, 0, n)
  {
    int x; cin>>x;
    freq[x]++;
  }
  int score = 0;
  for (auto &entry : freq) score += entry.second / 2;
  cout << score << ln;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}