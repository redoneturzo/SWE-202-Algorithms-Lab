#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

// Prim's algorithm on an adjacency list with a min-heap.
// adj[u] = list of (v, weight). Returns the MST cost and fills 'mst' with (parent, node, weight).
int spanningTree(int V, vector<vector<pair<int,int>>>& adj, vector<vector<int>>& mst) {
    // min-heap of (wt, node, parent): the lightest edge leaving the tree is on top
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
    vector<int> vis(V, 0);
    int sum = 0;

    pq.push({0, 0, -1});                    // start from vertex 0, no parent
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it[0], node = it[1], parent = it[2];

        if (vis[node]) continue;              // stale entry: already in the tree
        vis[node] = 1;
        sum += wt;
        if (parent != -1) mst.push_back({parent, node, wt});

        for (auto& edge : adj[node]) {
            int adjNode = edge.first, w = edge.second;
            if (!vis[adjNode]) pq.push({w, adjNode, node});
        }
    }
    return sum;
}

int main() {
    int V, E;
    cout << "Enter V and E: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v w), vertices 0.." << V - 1 << ":\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});             // undirected graph
    }

    vector<vector<int>> mst;
    int cost = spanningTree(V, adj, mst);

    if ((int)mst.size() != V - 1) {
        cout << "Graph is not connected\n";
        return 0;
    }
    cout << "Edge   Weight\n";
    for (auto& e : mst) cout << e[0] << " - " << e[1] << "   " << e[2] << "\n";
    cout << "Minimum Cost Spanning Tree: " << cost << endl;
    return 0;
}
