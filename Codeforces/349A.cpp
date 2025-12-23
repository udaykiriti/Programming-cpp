#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main()
{
  long int tf, fy, hn, n, c, i, a[100001];
  while (cin >> n)
  {
    FOR (i ,0,n)
      cin >> a[i];

    c = 1; tf = 0; hn = 0; fy = 0;
    FOR (i , 0, n)
    {
      if (a[i] == 25)
        tf++;
      else if (a[i] == 50)
      {
        if (tf < 1)
        {
          c = 0;
          break;
        }
        else
        {
          tf = tf - 1;
          fy = fy + 1;
        }
      }
      else if (a[i] == 100)
      {
        if (tf >= 1 && fy >= 1)
        {
          tf = tf - 1;
          fy = fy - 1;
        }
        else if (tf >= 3)
        {
          tf = tf - 3;
        }
        else
        {
          c = 0;
          break;
        }
      }
    }
    if (c == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}