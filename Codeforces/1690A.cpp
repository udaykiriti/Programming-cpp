#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long n; cin >> n;
        long a, b, c;
        if (n % 3 == 0) {
            a = b = c = (n - 3) / 3;
            a += 1; b += 2;
        } else if (n % 3 == 1) {
            a = b = c = (n - 4) / 3;
            a += 1; b += 3;
        } else {
            a = b = c = (n - 5) / 3;
            a += 2; b += 3;
        }
        cout << a << " " << b << " " << c << "\n";
    }
}
