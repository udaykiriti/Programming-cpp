#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define BYE return 0
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int solve(int n)
{
  if (n % 7 == 0) return n;
  FOR(i, 0, 10)
  {
    int x = ((n / 10) * 10) + i;
    if (x % 7 == 0) return x;
  }
  return -1;
}

int main()
{
  FastIO; int t;cin >> t;
  while (t--)
  {
    int n; cin >> n;
    cout << solve(n) << endl;
  }
  BYE;
}