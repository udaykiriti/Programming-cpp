#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p(n+1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];

    int L = 0, R = 0;
    for (int l = 1; l <= n-2 && L==0; l++) {
        for (int r = l+1; r <= n-1 && L==0; r++) {
            int s1 = p[l] % 3;
            int s2 = (p[r] - p[l]) % 3;
            int s3 = (p[n] - p[r]) % 3;

            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)) {
                L = l;
                R = r;
            }
        }
    }
    if (L == 0) cout << "0 0\n";
    else cout << L << " " << R << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
