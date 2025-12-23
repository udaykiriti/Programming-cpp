#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll int i, j, k;
  ll int sum = 0, count = 0;
  ll int n, b, d; cin >> n >> b >> d;
  ll int a[n];
  for (i = 0; i < n; i++)
    cin >> a[i];
  for (i = 0; i < n; i++)
  {
    if (a[i] > b)
      continue;
    sum += a[i];
    if (sum > d)
    {
      sum = 0;
      count++;
    }
  }
  cout << count;
  return 0;
}