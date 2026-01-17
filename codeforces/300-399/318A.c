#include <stdio.h>
#define ull unsigned long long

int main() {
    ull n, m; scanf("%llu %llu", &n, &m);
    if (n % 2 == 1) {
        if (m <= (n / 2 + 1))
            printf("%llu\n", 2 * m - 1);
        else
            printf("%llu\n", 2 * (m - (n / 2 + 1)));
    } else {
        if (m <= (n / 2))
            printf("%llu\n", 2 * m - 1);
        else
            printf("%llu\n", 2 * (m - (n / 2)));
    }
    return 0;
}