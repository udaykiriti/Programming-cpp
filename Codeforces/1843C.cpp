/*
Problem: Sum of Doubled Values (Codeforces 1843C)
Username: Polymath__
Email:udaykiriti9@gmail.com
Link: https://codeforces.com/problemset/problem/1843/C
github link: https://github.com/udaykiriti



You are given a single integer n.
You repeatedly perform the following operation:
- Add n to your answer.
- Replace n with n // 2 (integer division).
- Stop when n becomes 0.

Print the final answer for each test case.

Input:
The first line contains a single integer t (number of test cases).
Each test case contains a single integer n (1 ≤ n ≤ 10^18).

Output:
For each test case, print the answer.

Example:
Input:
2
10
3

Output:
18
4
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define multicase \
  int t;          \
  cin >> t;       \
  while (t--)     \
    solve();
#define GG return 0
void solve()
{
  i64 n; cin >> n;
  i64 res = 0;
  while (n)
  {
    res += n;
    n /= 2;
  }

  cout << res << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  GG;
}