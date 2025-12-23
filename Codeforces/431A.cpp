#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int a, b, c, d; cin >> a >> b >> c >> d;
  string s; cin >> s;
  int clry = 0;
  FOR (i, 0,s.size())
  {
    if (s[i] == '1')
    {
      clry += a;
      continue;
    }
    if (s[i] == '2')
    {
      clry += b;
      continue;
    }
    if (s[i] == '3')
    {
      clry += c;
      continue;
    }
    if (s[i] == '4')
    {
      clry += d;
      continue;
    }
  }
  cout << clry << endl;
  return 0;
}