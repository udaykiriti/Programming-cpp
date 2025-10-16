#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
        int n; ll x;
        cin >> n >> x;
        vector < ll > vec1(n), vec2(n), vec3(n);
        for (auto &x : vec1){
            cin >> x;
        }
        for (auto &x : vec2) {
            cin >> x;
        }
        for (int i = 0; i < n; i++) {
            vec3[i] = vec1[i];
        }
        ll z = 0;
        for (int i = 0; i < n; i++) {
            z += vec3[i] * vec2[i];
        }
        ll res = z;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int in = j - i;
                if (in < 0) in += n;
                if (vec1[in] < vec3[j]) {
                    z -= vec3[j] * vec2[j];
                    vec3[j] = vec1[in];
                    z += vec3[j] * vec2[j];
                }
            }
            ll TT = z + (ll) i * x;
            if (TT < res) res = TT;
        }

        cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
