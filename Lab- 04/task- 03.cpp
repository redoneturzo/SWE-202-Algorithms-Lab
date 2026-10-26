#include <bits/stdc++.h>
using namespace std;

// Function to solve Task 2 & Task 3 using Dijkstra's algorithm
void solveDijkstra(int V, vector<vector<int>> &edges, int src, int dest) {
    // Adjacency list: adj[u] holds pairs {weight, neighbour}
    vector<vector<pair<int,int>>> adj(V);
    for (auto e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u}); // Undirected graph
    }

    // Min-heap of {distance, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, 1e9);   // Distance array initialized to infinity
    vector<int> parent(V);      // Array to reconstruct path
    vector<int> cnt(V, 0);      // Array to count number of shortest paths

    for (int i = 0; i < V; i++) parent[i] = i;

    // Initialization for source vertex
    dist[src] = 0;
    cnt[src] = 1;               // Base case: 1 path to source
    pq.push({0, src});

    while (!pq.empty()) {
        int total_wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip stale heap entries to avoid duplicate path counting
        if (total_wt > dist[node]) continue;

        for (auto e : adj[node]) {
            int edgewt = e.first;
            int adjnode = e.second;

            // Case 1: Found a strictly shorter path to adjnode
            if (total_wt + edgewt < dist[adjnode]) {
                dist[adjnode] = total_wt + edgewt;
                cnt[adjnode] = cnt[node];           // Inherit path count from u
                parent[adjnode] = node;            // Update parent for path printing
                pq.push({dist[adjnode], adjnode});
            }
            // Case 2: Found another path with the exact same shortest distance
            else if (total_wt + edgewt == dist[adjnode]) {
                cnt[adjnode] += cnt[node];          // Add path count from u
            }
        }
    }

    // Print Shortest Distance
    cout << "Shortest distance: " << dist[dest] << endl;

    // Reconstruct Path (Task 2)
    vector<int> path;
    int curr = dest;
    while (curr != src) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    // Print Path formatted as 0 -> 1 -> 3
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << endl;

    // Print Total Number of Shortest Paths (Task 3)
    cout << "Number of shortest paths: " << cnt[dest] << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int src, dest;
    cin >> src >> dest;

    solveDijkstra(V, edges, src, dest);

    return 0;
}
