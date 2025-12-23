#include <cstdio>
#include <vector>

int main() {
    long t; scanf("%ld", &t);

    while (t--) {
        long n; scanf("%ld", &n);

        std::vector<long> a(n);
        for (long i = 0; i < n; ++i)
            scanf("%ld", &a[i]);

        long left = 1;
        while (left < n && a[left] == a[0])
            ++left;

        long right = 1;
        while (right < n && a[n - 1 - right] == a.back())
            ++right;

        long s = (left > right) ? left : right;
        if (a[0] == a.back()) 
            s = left + right;

        if (s > n) s = n;
        printf("%ld\n", n - s);
    }
    return 0;
}
