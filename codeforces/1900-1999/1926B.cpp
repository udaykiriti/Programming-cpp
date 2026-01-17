#include <bits/stdc++.h>
using namespace std;

void solve(){
  long n; cin >> n;
    bool triangle = true;
    long prev = 0;
    for (long row = 0; row < n; row++)
    {
      string s; cin >> s;
      long ones = 0;
      for (char c : s) ones += (c == '1');
      if (ones > 0 && prev > 0 && ones == prev) triangle = false;
      prev = ones;
    }
    cout << (triangle ? "TRIANGLE" : "SQUARE") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(NULL);
  long t; cin >> t;
  while (t--) solve();
  return 0;
}