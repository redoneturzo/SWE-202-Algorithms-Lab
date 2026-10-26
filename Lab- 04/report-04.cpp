#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Dijkstra's algorithm with Vertex Costs
void dijkstra(int V, const vector<vector<pair<int, int>>>& adj, const vector<int>& c, int src, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    // Initial cost for source node includes its own vertex cost c[src]
    dist[src] = c[src];
    pq.push({dist[src], src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int edge_wt = edge.second;

            // Modified weight: edge_wt + vertex cost of v
            int new_dist = dist[u] + edge_wt + c[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print Results
    if (dist[dest] == INF) {
        cout << "No path found between " << src << " and " << dest << endl;
        return;
    }

    cout << "Minimum total cost: " << dist[dest];

    // Reconstruct Path
    vector<int> path;
    for (int curr = dest; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    cout << " and Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of Vertices and Edges: ";
    if (!(cin >> V >> E)) return 0;

    vector<int> c(V);
    cout << "Enter costs for " << V << " vertices: ";
    for (int i = 0; i < V; ++i) {
        cin >> c[i];
    }

    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter " << E << " edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    int src, dest;
    cout << "Enter Source and Destination: ";
    cin >> src >> dest;

    dijkstra(V, adj, c, src, dest);

    return 0;
}
