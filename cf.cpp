#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SORT(x) sort((x).begin(), (x).end())
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tcase(0),t(1); cin >> t;
    while (++tcase,t--) {
        int n, m; cin >> n >> m;
        vector<ll> vec1(n), vec2(m);
        ll sa(0), sb(0);

        for (ll &x : vec1) {
            cin >> x; sa += x;
        }
        for (ll &x : vec2) {
            cin >> x; sb += x;
        }

        SORT(vec1);
        SORT(vec2);


        ll best (9.223372e+18);
        int win(0);

        for (int p = 0; p < m; ) {
            ll val = vec2[p];
            int cb = 0;
            while (p < m && vec2[p] == val) {
                p++; cb++;
            }

            int ca = (int)(upper_bound(vec1.begin(), vec1.end(), val) - lower_bound(vec1.begin(), vec1.end(), val));

            int dif = cb + ca;
            if (dif > win || (dif == win && val < best)) {
                win = dif;
                best = val;
            }
        }

        ll res = (win <= n) ? sa + sb : sa + sb - 2LL * (win - n) * best;
        cout << res << endl;
    }
    return 0;
}
