/*
Problem: Forbidden Value
You are given three integers n, k, x.
You need to represent n as the sum of some positive integers, each between 1 and k (inclusive), and none of them equal to x.
If possible, print "YES" and the number of summands, followed by the summands themselves.
Otherwise, print "NO".

Input:
The first line contains a single integer t (number of test cases).
Each test case contains three integers n, k, x.

Output:
For each test case, print the answer as described above.

Example:
Input:
3
5 2 2
6 2 1
7 3 3

Output:
NO
YES
3
2 2 2
YES
2
2 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define BYE return 0

void solve()
{
  int n, k, x;
  cin >> n >> k >> x;
  if (x == 1 && k == 1)
  {
    cout << "NO" << ln;
  }
  else if (x == 1 && k == 2 && n % 2)
  {
    cout << "NO" << ln;
  }
  else
  {
    if (x != 1)
    {
      cout << "YES" << ln;
      cout << n << ln;
      for (int i = 0; i < n; ++i)
        cout << 1 << ' ';
      cout << ln;
    }
    else
    {
      if (n % 2)
      {
        cout << "YES" << ln;
        cout << 1 + (n - 3) / 2 << ln;
        cout << 3 << ' ';
        n -= 3;
        for (int i = 0; i < n / 2; ++i)
          cout << 2 << ' ';
        cout << ln;
      }
      else
      {
        cout << "YES" << ln;
        cout << n / 2 << ln;
        for (int i = 0; i < n / 2; ++i)
          cout << 2 << ' ';
        cout << ln;
      }
    }
  }
}

int main()
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  BYE;
}

/*
some familiar issues & sugg.:
!----> [RE-READ THE CODE!]
!----> [invariants to array?]
!----> [what about freq of elem/chars?]
!----> [kinda back-tracking?]
!----> [use clear() at last if resize() used!]
!----> [look at global variables and their values]
!----> [llabs() for long long int type]
!----> [look at input size and time limit]
!----> [No sync with puts fn]
!----> [prefix vs suffix]
!----> [binary search? -> ubd, lbd]
!----> [array contains duplicate values!]
!----> [(a/b+1)*b vs uceil(a,b)*b]
!----> [unq_v for vec only]
!----> [bitmask vs unsigned; (1ull << i) -> pow2]
!----> [use gcd(), NOT __gcd() for ai < 0]
!----> [rec. lambda: function<ret.type(param types,..)>fn_name = ....lambda fn && always dyn arr(vec, ..]
*/