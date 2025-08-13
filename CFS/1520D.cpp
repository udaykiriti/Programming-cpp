#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

void solve()
{
  int n; cin >> n;
  vector<int> vec(n);
  for (int &x : vec)
    cin >> x;

  map<int, long long> freq;
  FOR (i,0,n)
  {
    int key = vec[i] - i;
    freq[key]++;
  }

  long long res = 0;
  for (auto &[key, count] : freq) res += count * (count - 1) / 2;
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}