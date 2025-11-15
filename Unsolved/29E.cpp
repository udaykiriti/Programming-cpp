#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
    vector<vector<pair<int, int>>> parent(n+1, vector<pair<int, int>>(n+1, make_pair(-1, -1)));

    queue<pair<int, int>> q;
    dist[1][n] = 0;
    q.push({1, n});

    while (!q.empty()) {
        int b = q.front().first;
        int a = q.front().second;
        q.pop();

        if (b == n && a == 1) {
            break;
        }

        for (int nb : adj[b]) {
            for (int na : adj[a]) {
                if (nb == na) continue;
                if (dist[nb][na] == -1) {
                    dist[nb][na] = dist[b][a] + 1;
                    parent[nb][na] = make_pair(b, a);
                    q.push({nb, na});
                }
            }
        }
    }

    if (dist[n][1] == -1) {
        cout << -1 << endl;
    } else {
        int k = dist[n][1];
        vector<int> bob_route, alex_route;
        int b_cur = n, a_cur = 1;
        while (b_cur != 1 || a_cur != n) {
            bob_route.push_back(b_cur);
            alex_route.push_back(a_cur);
            pair<int, int> p = parent[b_cur][a_cur];
            b_cur = p.first;
            a_cur = p.second;
        }
        bob_route.push_back(1);
        alex_route.push_back(n);

        reverse(bob_route.begin(), bob_route.end());
        reverse(alex_route.begin(), alex_route.end());

        cout << k << "\n";
        for (int i = 0; i < bob_route.size(); i++) {
            if (i > 0) cout << " ";
            cout << bob_route[i];
        }
        cout << "\n";
        for (int i = 0; i < alex_route.size(); i++) {
            if (i > 0) cout << " ";
            cout << alex_route[i];
        }
        cout << "\n";
    }

    return 0;
}
