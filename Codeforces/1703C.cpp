#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0
#define FastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)

void solve()
{
  int n; cin >> n;
  vector<int> final_digits(n);
  for (int i = 0; i < n; ++i) cin >> final_digits[i];
  vector<int> original_digits(n);
  for (int i = 0; i < n; ++i)
  {
    int b; string moves;cin >> b >> moves;
    int current_digit = final_digits[i];
    for (int j = b - 1; j >= 0; --j)
      if (moves[j] == 'U') current_digit = (current_digit - 1 + 10) % 10;
      else if (moves[j] == 'D') current_digit = (current_digit + 1) % 10;
    original_digits[i] = current_digit;
  }
  for (int i = 0; i < n; ++i) cout << original_digits[i] << " ";
  cout << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--)solve();
  EXIT;
}