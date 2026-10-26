#include <bits/stdc++.h>
using namespace std;

// Dijkstra function returning both distance and parent array for path reconstruction
pair<vector<int>, vector<int>> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for (auto e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, 1e9);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i; // Initially every node is parent of itself

    dist[src] = 0;
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
                parent[adjnode] = node; // Task 2 instruction: parent[v] = u
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return {dist, parent};
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int src, dest;
    cin >> src >> dest;

    auto [result, parent] = dijkstra(V, edges, src);


    cout << "Shortest Distance to destination " << dest << " is: " << result[dest] << endl;


    vector<int> path;
    int curr = dest;


    if (result[dest] == 1e9) {
        cout << "No path found!" << endl;
        return 0;
    }

    while (curr != src) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(src);

    reverse(path.begin(), path.end()); // Reverse the list

    cout << "Shortest Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
