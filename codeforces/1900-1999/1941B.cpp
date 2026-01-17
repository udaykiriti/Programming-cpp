#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    long t(1); std::cin >> t;
    while (t--) {
        long n; std::cin >> n;
        std::vector<long> a(n);
        for (long i = 0; i < n; ++i)
            std::cin >> a[i];

        bool valid = true;

        for (long i = 0; valid && i + 2 < n; ++i)
            if (a[i] < 0)
                valid = false;
            else {
                a[i + 1] -= 2 * a[i];
                a[i + 2] -= a[i];
            }

        if (valid && a[n - 2] == 0 && a[n - 1] == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}