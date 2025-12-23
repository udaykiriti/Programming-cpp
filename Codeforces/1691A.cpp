#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, x, even = 0, odd = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            if (x & 1) odd++;
            else even++;  
        }
        cout << min(even, odd) << '\n';
    }
    return 0;
}