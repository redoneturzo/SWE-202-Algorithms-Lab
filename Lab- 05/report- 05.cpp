#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

void cheapestRouteWithKEdges(int V, const vector<Edge>& edges, int source, int destination, int K) {
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[source] = 0;

    for (int i = 0; i < K; ++i) {
        vector<int> prev = dist;
        bool updated = false;

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;

            if (prev[u] != INF && prev[u] + w < dist[v]) {
                dist[v] = prev[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    if (dist[destination] == INF) {
        cout << "No route within " << K << " edges" << endl;
    } else {
        cout << "Best route cost for K = " << K << " is: " << dist[destination] << endl;
    }
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {2, 3, -3},
        {3, 1, -2},
        {1, 4, -4}
    };

    int source = 0;
    int destination = 4;

    for (int K = 1; K <= 4; ++K) {
        cheapestRouteWithKEdges(V, edges, source, destination, K);
    }

    return 0;
}
