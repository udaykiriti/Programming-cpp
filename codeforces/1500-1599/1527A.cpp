#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0;
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

void solve()
{
  int n; cin >> n;
  int msb = log2(n);
  cout << ((1 << msb) - 1) << endl;
}

int main()
{
  FastIO; int t; cin >> t;
  while (t--)
    solve();
  EXIT
}