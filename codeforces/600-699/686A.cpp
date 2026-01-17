#include <bits/stdc++.h>
#define ull unsigned long long
#define uc unsigned char
#define ui unsigned int

int main()
{
  uc op;
  ui n, d_ch = 0;
  ull i_cr, c;
  std::cin >> n >> i_cr;
  for (ui i = 0; i < n; ++i)
  {
    std::cin >> op >> c;
    if (op == '+')
    {
      i_cr += c;
    }
    else
    {
      if (c > i_cr)
        d_ch++;
      else
        i_cr -= c;
    }
  }
  std::cout << i_cr << " " << d_ch << std::endl;
  return 0;
}