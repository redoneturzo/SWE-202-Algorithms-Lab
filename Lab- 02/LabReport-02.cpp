#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    vector<int> indegree(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() == V) {
        cout << "";
        for (int v : topo) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "Graph contains a cycle." << endl;
    }

    return 0;
}
