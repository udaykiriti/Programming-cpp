#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define N 3
#define LL long long
#define S(x, y) { int t = x; x = y; y = t; }

bool p(int *a, int n) {
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) i--;
    if (i < 0) return false;
    int j = n - 1;
    while (a[j] <= a[i]) j--;
    S(a[i], a[j]);
    for (int l = i + 1, r = n - 1; l < r; l++, r--) S(a[l], a[r]);
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int r[N][2];
        LL a = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &r[i][0], &r[i][1]);
            a += 1LL * r[i][0] * r[i][1];
        }
        int s = (int)floor(sqrt(a));
        bool ok = false;

        if (1LL * s * s == a) {
            int q[] = {0, 1, 2};
            do {
                int w1 = r[q[0]][0], h1 = r[q[0]][1];
                int w2 = r[q[1]][0], h2 = r[q[1]][1];
                int w3 = r[q[2]][0], h3 = r[q[2]][1];

                if (w1 == s && w2 == s && w3 == s && h1 + h2 + h3 == s) ok = true;
                if (h1 == s && h2 == s && h3 == s && w1 + w2 + w3 == s) ok = true;
                if (h1 == s && w2 == s - w1 && w3 == s - w1 && h2 + h3 == s) ok = true;
                if (w1 == s && h2 == s - h1 && h3 == s - h1 && w2 + w3 == s) ok = true;

            } while (p(q, N) && !ok);
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}