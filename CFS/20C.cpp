#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
using Graph = vector<vector<pii>>;
const i64 INF = 1e18;

void printPath(const vector<i64> &parent, i64 node) {
  if (node != 1) printPath(parent, parent[node]);
  cout << node << " ";
}

void solve() {
  i64 n, m; cin >> n >> m;
  Graph adj(n + 1);
  for (i64 i = 0; i < m; i++) {
    i64 a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  vector<i64> dist(n + 1, INF), parent(n + 1, -1);
  priority_queue<pii, vector<pii>, greater<>> pq;

  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  if (dist[n] == INF) {
    cout << -1 << '\n';
  } else {
    printPath(parent, n);
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  solve();
  return 0;
}