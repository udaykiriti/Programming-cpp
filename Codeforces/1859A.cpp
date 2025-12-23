#include <bits/stdc++.h>
#define ll long long
#define nline '\n'
using namespace std;

void solve()
{
  ll n; cin >> n;
  vector<ll> arr(n);
  for (ll &x : arr)
    cin >> x;

  sort(arr.begin(), arr.end());

  if (arr.front() == arr.back())
  {
    cout << -1 << nline;
    return;
  }

  ll itr = 0;
  while (arr[itr] == arr[0])
    itr++;

  cout << itr << " " << n - itr << nline;
  for (int i = 0; i < itr; i++)
    cout << arr[i] << " ";
  for (int i = itr; i < n; i++)
    cout << arr[i] << " ";
  cout << nline;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll T; cin >> T;
  while (T--) solve();
  return 0;
}