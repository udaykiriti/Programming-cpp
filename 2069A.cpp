#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t(1),tcase(0);
    cin >> t;

    while(++tcase,t--) {
        int n;
        cin >> n;
        vector<int> a(n - 2);
        for (int &x : a) cin >> x;
        bool ok = true;
        for (int i = 0; i < n - 2;) {
            if (a[i] == 1) {
                ++i;
                int cnt = 0;
                while (i < n - 2 && a[i] != 1) {
                    ++cnt; ++i;
                }
                if (cnt && cnt < 2 && i < n - 2 && a[i] == 1)
                    ok = false;
            } else {
                ++i;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
