/*
    Problem Description:
    You are given an array a consisting of n integers.

    Let's call a pair of indices i, j good if 1 ≤ i < j ≤ n and gcd(ai, 2 * aj) > 1
    (where gcd(x, y) is the greatest common divisor of x and y).

    Find the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

    Input:
    The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.

    The first line of the test case contains a single integer n (2 ≤ n ≤ 2000) — the number of elements in the array.

    The second line of the test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 105).

    It is guaranteed that the sum of n over all test cases does not exceed 2000.

    Output:
    For each test case, output a single integer — the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

    Example:
    Input:
    3
    4
    3 6 5 3
    2
    1 7
    5
    1 4 2 4 1

    Output:
    4
    0
    9
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_VAL 100000
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long;

void solve()
{
  ll n, ans = 0;
  cin >> n;

  vector<ll> odds, evens, a;
  for (ll i = 0; i < n; ++i)
  {
    ll x;
    cin >> x;
    if (x % 2 == 0)
    {
      evens.push_back(x);
    }
    else
    {
      odds.push_back(x);
    }
  }

  a = evens;
  a.insert(a.end(), odds.begin(), odds.end());

  for (size_t i = 0; i < a.size(); ++i)
  {
    for (size_t j = i + 1; j < a.size(); ++j)
    {
      if (__gcd(a[i], 2 * a[j]) > 1)
      {
        ++ans;
      }
    }
  }

  cout << ans << "\n";
}

int main()
{
  FAST_IO;
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
