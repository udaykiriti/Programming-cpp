#include <bits/stdc++.h>

void solve()
{
  long n; std::cin >> n;
  std::string s; std::cin >> s;
  long a = 0, b = 0, c = 0, d = 0;
  for (char ch : s)
  {
    if (ch == 'A')
      a++;
    else if (ch == 'B')
      b++;
    else if (ch == 'C')
      c++;
    else if (ch == 'D')
      d++;
  }
  long cnt = std::min(a, n) + std::min(b, n) + std::min(c, n) + std::min(d, n);
  std::cout << cnt << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(NULL);
  long t; std::cin >> t;
  while (t--) solve();
  return 0;
}