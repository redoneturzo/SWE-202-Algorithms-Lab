#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int u, v, weight;
};

const int INF = 1e9;

void bellmanFord(int V, int E, vector<Edge>& edges, int source, int destination) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    dist[source] = 0;


    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }


    bool negativeCycle = false;
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative cycle detected." << endl;
        return;
    }


    if (dist[destination] == INF) {
        cout << "Shortest distance: INF" << endl;
        cout << "No path exists." << endl;
        return;
    }


    vector<int> path;
    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());


    cout << "Shortest distance: " << dist[destination] << endl;
    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    int V = 5;
    int E = 10;

    vector<Edge> edges = {
        {0, 1, 3}, {0, 2, 7}, {1, 2, 6}, {1, 3, 2}, {1, 4, -4},
        {2, 3, -3}, {3, 1, -2}, {3, 4, 4}, {4, 0, 2}, {4, 2, 1}
    };

    int source = 0;
    int destination = 4;

    bellmanFord(V, E, edges, source, destination);

    return 0;
}

