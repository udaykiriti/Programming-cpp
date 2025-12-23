#include <bits/stdc++.h>
using namespace std;

int main()
{

  long t; cin>>t;
  while (t--)
  {
    int a, b, c; cin>>a>>b>>c;
    bool ans = (a + b >= 10) || (b + c >= 10) || (c + a >= 10);
    puts(ans ? "YES" : "NO");
  }
}