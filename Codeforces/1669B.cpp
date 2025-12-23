#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"

int main()
{
  stop_sync; untie_ios;
  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i)
      cin >> a[i], freq[a[i]]++;
    bool found = false;
    for (auto &entry : freq)
      if (entry.second >= 3)
      {
        cout << entry.first << ln;
        found = true;
        break;
      }

    if (!found) cout << -1 << ln;
  }
  return 0;
}