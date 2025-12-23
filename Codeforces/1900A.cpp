#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll n; cin >> n;
  string s; cin >> s;

  ll no_of_dots = 0;
  for (char c : s)
    if (c == '.')
      no_of_dots++;

  ll max_dots = 0, curr_dots = 0;
  for (char c : s)
  {
    if (c == '.')
    {
      curr_dots++;
    }
    else
    {
      max_dots = max(max_dots, curr_dots);
      curr_dots = 0;
    }
  }
  max_dots = max(max_dots, curr_dots);

  if (max_dots >= 3)
    cout << 2 << endl;

  else
    cout << no_of_dots << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); 
  int t; cin>>t;
  while(t--) solve();
}