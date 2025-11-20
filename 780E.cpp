#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int n, m, k, a[maxn * 2], cnt;
bool vis[maxn];
vector < int > e[maxn];

void dfs(int u) {
    vis[u] = 1;
    a[++ cnt] = u;
    for (auto v : e[u]) if (!vis[v]) {
        dfs(v);
        a[++cnt] = u;
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    int lim = (2 * n + k - 1) / k;
    vector < vector < int > > res(k, vector < int > (0));
    dfs(1);
    int cur = 1;
    for (int i = 0; i < k; i ++) {
        while (res[i].size() < lim && cur <= cnt) {
            res[i].push_back(a[cur ++]);
        }
    }
    
    for (int i = 0; i < k; i ++) {
        cout << res[i].size() << " ";
        for (auto j : res[i]) cout << j << " "; 
        cout << '\n';
    }
    return 0;
}