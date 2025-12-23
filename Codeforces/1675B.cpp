#include <bits/stdc++.h>
using namespace std;

void test() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    long long ops = 0;
    for (int i = n - 2; i >= 0; --i) {
        while (a[i] >= a[i + 1] && a[i] > 0) {
            a[i] /= 2;
            ++ops;
        }
        if (a[i] >= a[i + 1]) {
            cout << "-1\n";
            return;
        }
    }

    cout << ops << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int tc; cin >> tc;
    while (tc--) test();
    return 0;
}