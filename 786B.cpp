#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
constexpr ll inf = ll(1e18)+9;
int main() {
    // input
    int original_n, q, start; scanf("%d%d%d", &original_n, &q, &start); -- start;
    // prepare a graph
    int n = 1 << (32 - __builtin_clz(original_n - 1));
    vector<vector<pair<int, int> > > g(n + n-1 + n-1);
    const int src = n;
    const int dst = n + n-1;
    auto coalesce = [&](int i, int base) { assert (i < 2*n-1); return i < n-1 ? base + i : i - (n-1); };
    repeat (i,n-1) {
        int l = 2*i+1;
        int r = 2*i+2;
        g[src + i].emplace_back(coalesce(l, src), 0);
        g[src + i].emplace_back(coalesce(r, src), 0);
        g[coalesce(l, dst)].emplace_back(dst + i, 0);
        g[coalesce(r, dst)].emplace_back(dst + i, 0);
    }
    // add edges
    while (q --) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int v, u, cost; scanf("%d%d%d", &v, &u, &cost); -- v; -- u;
            g[v].emplace_back(u, cost);
        } else if (type == 2) {
            int v, l, r, cost; scanf("%d%d%d%d", &v, &l, &r, &cost); -- v; -- l;
            for (l += n, r += n; l < r; l /= 2, r /= 2) {
                if (l % 2 == 1) g[v].emplace_back(coalesce((l ++) - 1, src), cost);
                if (r % 2 == 1) g[v].emplace_back(coalesce((-- r) - 1, src), cost);
            }
        } else if (type == 3) {
            int v, l, r, cost; scanf("%d%d%d%d", &v, &l, &r, &cost); -- v; -- l;
            for (l += n, r += n; l < r; l /= 2, r /= 2) {
                if (l % 2 == 1) g[coalesce((l ++) - 1, dst)].emplace_back(v, cost);
                if (r % 2 == 1) g[coalesce((-- r) - 1, dst)].emplace_back(v, cost);
            }
        }
    }
    // dijkstra
    vector<ll> dist(n + n-1 + n-1, inf);
    priority_queue<pair<ll, int> > que;
    dist[start] = 0;
    que.emplace(- dist[start], start);
    while (not que.empty()) {
        ll cost; int i; tie(cost, i) = que.top(); que.pop();
        if (dist[i] < - cost) continue;
        for (auto it : g[i]) {
            int j; ll delta; tie(j, delta) = it;
            if (- cost + delta < dist[j]) {
                dist[j] = - cost + delta;
                que.emplace(cost - delta, j);
            }
        }
    }
    // output
    repeat (i,original_n) {
        if (i) printf(" ");
        printf("%lld", dist[i] == inf ? -1 : dist[i]);
    }
    printf("\n");
    return 0;
}