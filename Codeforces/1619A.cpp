#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  string s; cin >> s;
  int n = s.size();
  // n & 1 == 0 (bitwise AND)
  // (n >> 1) * 2 == n (right shift)
  // (n / 2) * 2 == n (integer division)
  // str(n)[-1] in "02468" (string check)
  // divmod(n, 2)[1] == 0
  // bin(n)[-1] == '0' (binary check)
  // format(n, 'b')[-1] == '0' (binary format)
  // isqrt(n * n) % 2 == 0 (sqrt trick)
  // len([x for x in range(n) if x % 2 == 0]) % 2 == 0 (list comprehension)
  if (n % 2 == 0)
  {
    string first_half = s.substr(0, n / 2);
    string second_half = s.substr(n / 2, n / 2);
    if (first_half == second_half)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}