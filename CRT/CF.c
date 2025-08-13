// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define MOD 998244353
// #define MAXN 1000005
// #define MAX(a, b) ((a) > (b) ? (a) : (b))

// #define FOR(i, start, end) for (int i = start; i < end; ++i)
// #define FORI(i, n) FOR(i, 0, n)
// #define ALLOC(type, var, size) type *var = (type *)malloc((size) * sizeof(type))
// #define FREE(ptr) free(ptr)

// long long pow2[MAXN] = {1};

// int main() {
//     int T;
//     scanf("%d", &T);

//     while (T--) {
//         int n;
//         scanf("%d", &n);

//         ALLOC(int, p, n);
//         ALLOC(int, q, n);
//         ALLOC(int, posP, n + 1);
//         ALLOC(int, posQ, n + 1);

//         FORI(i, n) {
//             scanf("%d", &p[i]);
//             posP[p[i]] = i;
//         }
//         FORI(i, n) {
//             scanf("%d", &q[i]);
//             posQ[q[i]] = i;
//         }

//         if (pow2[n] == 0) {
//             FOR(i, 1, n + 1) {
//                 pow2[i] = (pow2[i - 1] * 2) % MOD;
//             }
//         }

//         ALLOC(int, Pmax, n);
//         ALLOC(int, Qmax, n);
//         ALLOC(int, r, n);

//         Pmax[0] = p[0];
//         Qmax[0] = q[0];
//         FOR(i, 1, n) {
//             Pmax[i] = MAX(Pmax[i - 1], p[i]);
//             Qmax[i] = MAX(Qmax[i - 1], q[i]);
//         }

//         FORI(i, n) {
//             int e = MAX(Pmax[i], Qmax[i]);
//             int s;

//             if (Pmax[i] > Qmax[i]) {
//                 int j = posP[e];
//                 int k = i - j;
//                 s = q[k];
//             } else if (Qmax[i] > Pmax[i]) {
//                 int k = posQ[e];
//                 int j = i - k;
//                 s = p[j];
//             } else {
//                 int j1 = posP[e];
//                 int k1 = i - j1;
//                 int s1 = (k1 >= 0 && k1 < n) ? q[k1] : -1;
//                 int k2 = posQ[e];
//                 int j2 = i - k2;
//                 int s2 = (j2 >= 0 && j2 < n) ? p[j2] : -1;
//                 s = MAX(s1, s2);
//             }

//             r[i] = (pow2[e] + pow2[s]) % MOD;
//         }

//         FORI(i, n) {
//             printf("%lld ", r[i]);
//         }
//         printf("\n");

//         FREE(p);
//         FREE(q);
//         FREE(posP);
//         FREE(posQ);
//         FREE(Pmax);
//         FREE(Qmax);
//         FREE(r);
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MOD 998244353

long long pow2[100001];

int main() {
    int T;
    scanf("%d", &T);
    int maxN = 0;

    while (T--) {
        int n;
        scanf("%d", &n);
        int p[n], q[n], posP[n], posQ[n];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            posP[p[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
            posQ[q[i]] = i;
        }
        
        if (pow2[n] == 0) {
            pow2[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow2[i] = (pow2[i - 1] * 2) % MOD;
            }
        }

        int Pmax[n], Qmax[n];
        Pmax[0] = p[0];
        Qmax[0] = q[0];

        for (int i = 1; i < n; i++) {
            Pmax[i] = (Pmax[i - 1] > p[i]) ? Pmax[i - 1] : p[i];
            Qmax[i] = (Qmax[i - 1] > q[i]) ? Qmax[i - 1] : q[i];
        }

        int r[n];

        for (int i = 0; i < n; i++) {
            int e = (Pmax[i] > Qmax[i]) ? Pmax[i] : Qmax[i];
            int s;

            if (Pmax[i] > Qmax[i]) {
                int j = posP[e];
                int k = i - j;
                s = q[k];
            } else if (Qmax[i] > Pmax[i]) {
                int k = posQ[e];
                int j = i - k;
                s = p[j];
            } else {
                int j1 = posP[e];
                int k1 = i - j1;
                int s1 = (k1 >= 0 && k1 < n) ? q[k1] : -1;
                int k2 = posQ[e];
                int j2 = i - k2;
                int s2 = (j2 >= 0 && j2 < n) ? p[j2] : -1;
                s = (s1 > s2) ? s1 : s2;
            }
            r[i] = (pow2[e] + pow2[s]) % MOD;
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", r[i]);
        }
        printf("\n");
    }

    return 0;
}
