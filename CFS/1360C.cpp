#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INPUT(x) cin >> x
#define FOR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main()
{
  int t, n, a[101]; INPUT(t);
  while (t--)
  {
    int even = 0, odd = 0, dif = 0, diff = 0;
    INPUT(n);

    FOR(i, 0, n)
    {
      INPUT(a[i]);
      if (a[i] % 2 == 0)
        even++;
      else
        odd++;
    }

    sort(a, a + n);

    FOR(i, 1, n)
    {
      dif = abs(a[i] - a[i - 1]);
      if (dif == 1)
        diff++;
    }

    if (even % 2 == 0 && odd % 2 == 0)
    {
      cout << "YES" << endl;
    }
    else if (even % 2 == 1 && odd % 2 == 1)
    {
      if (diff >= 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}