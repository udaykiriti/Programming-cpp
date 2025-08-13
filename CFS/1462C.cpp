#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define PRINT(x) cout << x << endl
#define INPUT(x) cin >> x
#define SORT(s) sort(s.begin(), s.end())
using namespace std;

int main()
{
  fastread();
  ll t, n;
  INPUT(t);

  while (t--)
  {
    string s;
    ll x = 9, sum = 0;
    set<int> S;
    INPUT(n);

    if (n < 10)
    {
      PRINT(n);
      continue;
    }

    while (x > 0)
    {
      if (n - sum >= x)
      {
        sum += x;
        s += (x + '0');
        S.insert(x);
      }
      x--;
    }

    if (s.length() != S.size() || sum != n)
    {
      PRINT(-1);
    }
    else
    {
      SORT(s);
      PRINT(s);
    }
  }
  return 0;
}