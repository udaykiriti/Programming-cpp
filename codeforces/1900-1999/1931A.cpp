#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0;
#define FastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= k)

void solve()
{
  int n; cin >> n;
  FOR(i, 1, 27){
    FOR(j, 1, 27){
      int third = n - (i + j);
      if (third >= 1 && third <= 26)
      {
        cout << char('a' + i - 1) << char('a' + j - 1) << char('a' + third - 1) << endl;
        return;
     }
    }
  }
}

int main()
{
  FastIO() int t = 1;
  cin >> t;
  while (t--)
    solve();
  EXIT
}