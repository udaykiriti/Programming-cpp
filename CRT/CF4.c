#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define FOR(i,n) for(int i=0;i<(n);++i)
#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a, const void *b) {
    int f1 = (*(int **)a)[0], v1 = (*(int **)a)[1];
    int f2 = (*(int **)b)[0], v2 = (*(int **)b)[1];
    return f1 != f2 ? f1 - f2 : v1 - v2;
}

void solve() {
    int n, m; scanf("%d%d", &n, &m);
    int *a = malloc(m * sizeof(int));
    FOR(i, m) scanf("%d", &a[i]);

    int **v = malloc(m * sizeof(int *));
    FOR(i, m) {
        v[i] = malloc(2 * sizeof(int));
        v[i][0] = a[i] / 100; v[i][1] = a[i];
    }
    qsort(v, m, sizeof(int *), cmp);

    int *fl = malloc(m * sizeof(int)), *id = malloc(m * sizeof(int));
    FOR(i, m) fl[i] = v[i][0], id[i] = v[i][1];

    ll *T = malloc(n * sizeof(ll));
    FOR(i, n) T[i] = llabs((ll)fl[i] - (ll)fl[m - 1 - i]);

    ll *P = calloc(n + 1, sizeof(ll));
    FOR(i, n) P[i + 1] = P[i] + T[i];

    ll best = -1; int bk = 0;
    FOR(k, n + 1) {
        ll val = P[k] + P[n - k];
        if (val > best) best = val, bk = k;
    }

    int *A = malloc(n * sizeof(int)), *B = malloc(n * sizeof(int)), cnt = 0;
    FOR(i, bk) A[cnt++] = id[i];
    for (int i = m - (n - bk); i < m; ++i) A[cnt++] = id[i];

    cnt = 0;
    FOR(i, n - bk) B[cnt++] = id[i];
    for (int i = m - bk; i < m; ++i) B[cnt++] = id[i];

    FOR(i, n) {
        int ar = A[i], br = B[n - 1 - i];
        FOR(j, 6) printf("%d%c", j % 2 == 0 ? ar : br, j < 5 ? ' ' : '\n');
    }

    FOR(i, m) free(v[i]);
    free(v); free(a); free(fl); free(id); free(T); free(P); free(A); free(B);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}
