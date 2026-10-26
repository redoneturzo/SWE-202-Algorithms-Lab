#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <climits>
using namespace std;

// Prim's algorithm on an adjacency list with a min-heap, allowing an optional edge (skipU, skipV) to be excluded.
int spanningTree(int V, vector<vector<pair<int,int>>>& adj, vector<vector<int>>& mst, int skipU = -1, int skipV = -1) {
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
    vector<int> vis(V, 0);
    int sum = 0;
    mst.clear();

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

            // Temporarily skip the target edge from the MST[cite: 1]
            if ((node == skipU && adjNode == skipV) || (node == skipV && adjNode == skipU)) {
                continue;
            }

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
    int initialCost = spanningTree(V, adj, mst);

    if ((int)mst.size() != V - 1) {
        cout << "Graph is not connected\n";
        return 0;
    }

    cout << "Initial Minimum Cost Spanning Tree: " << initialCost << "\n\n";

    int secondBestCost = INT_MAX;
    vector<vector<int>> secondBestMstEdges;

    // Step 1 & 2: For each of the V - 1 edges of T, temporarily remove it and run Prim's algorithm[cite: 1]
    for (auto& e : mst) {
        int u = e[0], v = e[1];
        vector<vector<int>> tempMst;
        int cost = spanningTree(V, adj, tempMst, u, v);

        // Step 2: Skip if fewer than V vertices are reached (graph becomes disconnected)[cite: 1]
        if ((int)tempMst.size() == V - 1) {
            // Step 3: Find the cheapest among all trees found[cite: 1]
            if (cost < secondBestCost && cost > initialCost) {
                secondBestCost = cost;
                secondBestMstEdges = tempMst;
            }
        }
    }

    if (secondBestCost == INT_MAX) {
        cout << "No second best MST exists.\n";
    } else {
        cout << "Second Best MST Cost: " << secondBestCost << "\n";
        cout << "Edge   Weight\n";
        for (auto& e : secondBestMstEdges) {
            cout << e[0] << " - " << e[1] << "   " << e[2] << "\n";
        }
    }

    return 0;
}
