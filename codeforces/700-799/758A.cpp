#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  int max_wealth = *max_element(a.begin(), a.end());

  int total_cost = 0;
  for (int i = 0; i < n; i++)
    total_cost += max_wealth - a[i];
  cout << total_cost << endl;
  return 0;
}