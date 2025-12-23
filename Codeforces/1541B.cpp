#include <bits/stdc++.h>
using ll = long long;
using pii = std::pair<int, int>;

void solve()
{
  ll n; std::cin >> n;
  std::vector<pii> arr(n);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> arr[i].first;
    arr[i].second = i + 1;
  }

  std::sort(arr.begin(), arr.end());
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      ll product = 1LL * arr[i].first * arr[j].first;
      if (product > 2 * n)
        break;
      if (product == arr[i].second + arr[j].second)
        ++count;
    }
  }
  std::cout << count;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int testCases;
  std::cin >> testCases;
  while (testCases--)
  {
    solve();
    std::cout << '\n';
  }
  return 0;
}