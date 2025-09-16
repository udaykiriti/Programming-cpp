#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define stop_sync ios::sync_with_stdio(false) 
#define untie_ios cin.tie(nullptr) 
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())

const int MOD = 1e9 + 7;
int main(void){
    stop_sync; untie_ios;
    int t; cin >> t;
    while (t--)
    {
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
}
