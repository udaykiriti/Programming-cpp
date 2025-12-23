#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll n; cin >> n;
  string s; cin >> s;
  int j = 2;
  for (ll i = 0; i < n;)
  {
    cout << s.at(i);
    i = i + j;
    j++;
  }
  cout << endl;
  return 0;
}