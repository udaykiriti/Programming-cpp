/*
 *                                                     ----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          --~ ~~
 *                    -.            \_|//     |||\  ~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \            _/-
 *         ---~~~.==~||\=_    -_--~/_-~|-   |\   \        _/~
 *     _-~~     .=~    |  \-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       --
 *                       |--_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-____--~-/                  ==.
 *                       ((->/~   '.|||' -_|    -/ ,              . _||
 *                                  -_     ~\      ---l__i__i__i--_/
 *                                  _-~-__   ~)  \--______________--
 *                                //.-~~~-~_--~- |-------~~~~~~
 *                                       //.-~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                       DiVine BeAst bleSSes, may there be no buGs
 */

/*
  author:  -----          
  created: 04 23:35:26    
*/

#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 2e6 + 5;
int t, n, m, x, y, tmr, in[N], low[N], vis[N], cid[N], cmps, ch[N], l, r, md, ans;
vector<int> g[N], stk, nds, tmp;
vector<pair<int, int>> edgs;

void dfs(int v) {
    in[v] = low[v] = ++tmr;
    stk.push_back(v), vis[v] = 1;
    for (int u : g[v]) {
        if (!in[u]) dfs(u);
        if (vis[u]) low[v] = min(low[v], low[u]);
    }
    if (in[v] == low[v]) {
        ch[cmps] = v;
        while (1) {
            int u = stk.back(); stk.pop_back();
            vis[u] = 0, cid[u] = cmps;
            if (u == v) break;
        }
        cmps++;
    }
}

int Not(int x) { return (x <= 4 * n ? x + 4 * n : x - 4 * n); }

void add(int i, int j) {
    g[Not(i)].push_back(j);
    g[Not(j)].push_back(i);
}

void build(int p, int l, int r) {
    nds.push_back(p);
    if (l == r) return;
    int md = (l + r) / 2;
    build(p * 2, l, md);
    build(p * 2 + 1, md + 1, r);
    g[p].push_back(p * 2);
    g[p].push_back(p * 2 + 1);
    g[Not(p)].push_back(Not(p * 2));
    g[Not(p)].push_back(Not(p * 2 + 1));
}

void get(int p, int l, int r, int a, int b) {
    if (a <= l && r <= b) { tmp.push_back(p); return; }
    if (a > r || l > b) return;
    int md = (l + r) / 2;
    get(p * 2, l, md, a, b);
    get(p * 2 + 1, md + 1, r, a, b);
}

void clr() {
    int limit = min(8 * n, N - 1);
    for (x = 0; x <= limit; x++) {
        in[x] = vis[x] = low[x] = cid[x] = ch[x] = 0;
        g[x].clear();
    }
    debug(nds);
    stk.clear();
    nds.clear();
    debug(stk);
    tmr = cmps = 0;
}

bool ok(int md) {
    for (auto p : edgs) add(p.first, p.second);
    for (int pos = 1; pos <= n; pos++) {
        tmp.clear();
        get(1, 1, n, pos, pos);
        int y = tmp.back();
        if (pos > 1) {
            tmp.clear();
            get(1, 1, n, max(1, pos - md + 1), pos - 1);
            for (int z : tmp) add(Not(y), Not(z));
        }
        if (pos < n) {
            tmp.clear();
            get(1, 1, n, pos + 1, min(n, pos + md - 1));
            for (int z : tmp) add(Not(y), Not(z));
        }
    }
    for (int node : nds) {
        if (!in[node]) dfs(node);
        if (!in[Not(node)]) dfs(Not(node));
    }
    for (int node : nds)
        if (cid[node] == cid[Not(node)]) return 0;
    return 1;
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        edgs.clear();
        clr();
        build(1, 1, n);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            tmp.clear(); get(1, 1, n, x, x); int nx = tmp.back();
            tmp.clear(); get(1, 1, n, y, y); int ny = tmp.back();
            edgs.push_back({nx, ny});
        }
        l = ans = 1; r = n;
        while (l <= r) {
            md = (l + r) / 2;
            clr();
            build(1, 1, n);
            if (ok(md)) ans = md, l = md + 1;
            else r = md - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
