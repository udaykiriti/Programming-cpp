#include <bits/stdc++.h>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(NULL);

  long t; std::cin >> t;

  while (t--)
  {
    long n; std::cin >> n;
    std::string s; std::cin >> s;
    long cnt = 0;
    for (std::size_t p = 1; p < s.size(); ++p)
    {
      if (s[p - 1] == '*' && s[p] == '*')
        break;
      if (s[p] == '@')
        ++cnt;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}