#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

void solve()
{
  int n; cin >> n;
  vector<int> worms(n);
  cin >> worms[0];
  FOR (i,1,n)
  {
    cin >> worms[i];
    worms[i] += worms[i - 1];
  }

  int m; cin >> m;
  while (m--)
  {
    int query; cin >> query;
    int left = 0, right = n - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (worms[mid] < query)
        left = mid + 1;
      else
        right = mid - 1;
    }
    cout << left + 1 << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}