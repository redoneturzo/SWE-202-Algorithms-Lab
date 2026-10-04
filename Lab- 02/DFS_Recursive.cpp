#include <bits/stdc++.h>
using namespace std;

void DFS(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}

int main() {
    int n, e;

    cin >> n >> e;

    vector<vector<int>> adj(n);

    // Read edges
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);

    cout << "DFS order: ";
    DFS(start, adj, visited);
    cout << endl;

    return 0;
}