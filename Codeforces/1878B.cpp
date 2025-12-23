#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long current = 1;
        for (long long i = 0; i < n; i++) {
            cout << current << ' ';
            current += 2;  
        }
        cout << '\n';
    }
    return 0;
}
