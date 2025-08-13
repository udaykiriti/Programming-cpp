#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= k)

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    FOR(i, 0, n) cin >> grid[i];
    int minX = n, minY = m, maxX = -1, maxY = -1;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (grid[i][j] == '#') {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }
    int centerX = (minX + maxX) / 2 + 1;
    int centerY = (minY + maxY) / 2 + 1;
    cout << centerX << " " << centerY << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    EXIT;
}