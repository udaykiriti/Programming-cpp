#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
<<<<<<< HEAD

const int MOD = 1e9 + 7;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n, a, b, c; cin >> n >> a >> b >> c;
        int ans = 3 * (n / (a + b + c));
        n %= (a + b + c);

        if (n > 0) {
            ++ans;
            n -= a;
        }
        if (n > 0) {
            ++ans;
            n -= b;
        }
        if (n > 0) {
            ++ans;
            n -= c;
        }
        cout << ans << ln;
    } return 0;
=======
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int ans = 3 * (n / (a + b + c));
    n %= (a + b + c);
    if (n > 0) {
      ++ans;
      n -= a;
    }
    if (n > 0) {
      ++ans;
      n -= b;
    }
    if (n > 0) {
      ++ans;
      n -= c;
    }
    cout << ans << ln;
  }
  return 0;
>>>>>>> 45f19de (Simplify main function and improve input handling)
}
