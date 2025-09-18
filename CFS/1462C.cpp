#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(nullptr);
    long long t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        if (n < 10) {
            cout << n << "\n";
            continue;
        }

        string s;
        long long x = 9, sum = 0;
        set<int> digits;

        while (x > 0) {
            if (n - sum >= x) {
                sum += x;
                s.push_back(char(x + '0'));
                digits.insert(x);
            }
            x--;
        }
        if ((long long)s.length() != (long long)digits.size() || sum != n) {
            cout << -1 << "\n";
        } else {
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
    }
    return 0;
}
