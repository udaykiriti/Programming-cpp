#include <bits/stdc++.h>
using namespace std;

bool is_sorted_by_parity(vector<int> &a)
{
  vector<int> even, odd;
  for (int x : a)
  {
    if (x % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  vector<int> merged;
  int ei = 0, oi = 0;
  for (int x : a)
  {
    if (x % 2 == 0)
      merged.push_back(even[ei++]);
    else
      merged.push_back(odd[oi++]);
  }

  return is_sorted(merged.begin(), merged.end());
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    cout << (is_sorted_by_parity(a) ? "YES" : "NO") << '\n';
  }
  return 0;
}