/******************************
 *    author:  ....           *
 *    created: 19 10:54:26    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
bool solve() {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        int h; cin >> h;
        if (abs(h - H) % k) continue;
        int d = abs(h - H) / k;
        cnt += 1 <= d && d <= m - 1;
    }
    cout << cnt << endl;
    return true;
}
 
int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        if (!solve()) 
            cout << -1 << endl;
    }
    return 0;
}