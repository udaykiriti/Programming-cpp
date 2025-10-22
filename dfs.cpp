#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

// Adjacency list for unweighted graph: array of vectors
vector<int> adj[N];
//vector<pair<int, int>> adj[N]; // adj[u] = list of (neighbor, weight) pairs
// visited array to mark nodes as visited during DFS
bool visited[N];

//Print Nodes
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    
    // Curr node to all edges
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;  
    cin >> n >> m;  // number of nodes(vertices) and edges

    // Read edges and build adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v; 
        cin >> u >> v;

        adj[u].push_back(v);  // edge u -> v

        // For undirected graph, also add reverse edge
        adj[v].push_back(u);  
    }

    /*
    // If the graph is weighted, use this instead:
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});   // edge u->v with weight w
        // For weighted undirected graph, add reverse edge too:
        adj[v].push_back({u, w});
    }
    */

    int start; 
    cin >> start;  // Starting node for DFS
    dfs(start);  // Run DFS and print nodes reachable from start

    return 0;
}
