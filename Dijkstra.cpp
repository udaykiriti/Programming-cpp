#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (distance, node)

// Dijkstra's algorithm
vector<int> dijkstra(int n, vector<vector<pii>>& adj, int start) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // comment this line if graph is directed
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;

    vector<int> dist = dijkstra(n, adj, start);

    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
