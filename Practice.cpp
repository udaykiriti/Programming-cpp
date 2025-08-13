#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 2; i <= sqrt(n); i++) //i*i<=n(we can use this instead of sqrt(n))
  {
    if (n % i == 0)
    {
      cout << "No";
      return;
    }
  }
  cout << "Yes";
}