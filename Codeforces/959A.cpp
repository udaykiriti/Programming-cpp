#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll n; cin >> n;
  // n & 1 == 0 (bitwise AND)
  // (n >> 1) * 2 == n (right shift)
  // (n / 2) * 2 == n (integer division)
  // str(n)[-1] in "02468" (string check)
  // divmod(n, 2)[1] == 0
  // bin(n)[-1] == '0' (binary check)
  // format(n, 'b')[-1] == '0' (binary format)
  // isqrt(n * n) % 2 == 0 (sqrt trick)
  // len([x for x in range(n) if x % 2 == 0]) % 2 == 0 (list comprehension)
  if (n & 1) cout << "Ehab" << endl;
  else cout << "Mahmoud" << endl;
}