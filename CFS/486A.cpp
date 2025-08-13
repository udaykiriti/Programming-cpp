#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll n; cin >> n;
  ll evn = n / 2;
  ll oddn = n % 2 == 0 ? n / 2 : (n / 2 + 1);
  ll sumevn = evn * (evn + 1);
  ll sumoddn = oddn * oddn;
  ll sum = sumevn - sumoddn;
  cout << sum;
  return 0;
}