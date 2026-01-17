/*
Problem: Insert Digit
You are given a positive integer n and a digit d (0 ≤ d ≤ 9). You are also given a string s of length n, consisting of digits.
You need to insert the digit d into the string s in such a way that the resulting number is as large as possible.

Input:
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case consists of two lines:
- The first line contains two integers n and d (1 ≤ n ≤ 100, 0 ≤ d ≤ 9).
- The second line contains a string s of length n.

Output:
For each test case, print the resulting string after inserting d to maximize the number.

Example:
Input:
3
4 5
1234
3 9
111
1 0
0

Output:
51234
9111
00
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define BYE return 0
void solve()
{
  int n; char d; string s;
  cin >> n >> d >> s;
  bool inserted = false;
  FOR(i, 0, n)
  {
    if (!inserted && s[i] < d)
    {
      cout << d;
      inserted = true;
    }
    cout << s[i];
  }
  if (!inserted)
    cout << d;
  cout << '\n';
}

int main()
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  BYE;
}