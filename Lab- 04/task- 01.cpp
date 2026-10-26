#include <bits/stdc++.h>
using namespace std;

// Shortest distance from src to every vertex (directed, with negative weights)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Adjacency list: adj[u] holds pairs {weight, neighbour}
    vector<vector<pair<int,int>>> adj(V);
    for (auto e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({wt, v});  // Only directed edge (u -> v)
    }

    // Min-heap of {distance, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);               // 1e9 stands for "infinity"

    dist[src] = 0;                          // source distance is 0
    pq.push({0, src});

    while (!pq.empty()) {
        int total_wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto e : adj[node]) {
            int edgewt = e.first;
            int adjnode = e.second;

            if (total_wt + edgewt < dist[adjnode]) {
                dist[adjnode] = total_wt + edgewt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int src;
    cin >> src;

    vector<int> result = dijkstra(V, edges, src);

    for (int i = 0; i < V; i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
