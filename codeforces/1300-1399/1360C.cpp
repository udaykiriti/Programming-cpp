#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a[101];
    cin >> t;
    while (t--) {
        int even = 0, odd = 0, diff = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even++;
            else odd++;
        }

        sort(a, a + n);
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) == 1) diff++;
        }

        if ((even % 2 == 0 && odd % 2 == 0) || (even % 2 == 1 && odd % 2 == 1 && diff > 0)) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
