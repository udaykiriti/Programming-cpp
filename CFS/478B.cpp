#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define endl '\n'

ll int pairs(long long int n)
{
  return n * (n - 1) / 2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll int n, m; cin >> n >> m;
  ll int a(n / m), b(n % m);
  ll int min = pairs(a) * (m - b) + pairs(a + 1) * b;
  ll int max = pairs(n - m + 1);
  cout << min << " " << max << endl;
  return 0;
}