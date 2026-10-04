#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int start, const vector<vector<int>>& adj) {
    int n = adj.size();

    vector<bool> visited(n, false);
    stack<int> st;

    visited[start] = true;
    st.push(start);

    cout << "DFS order: ";

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        cout << u << " ";

        // Push neighbours in reverse order
        // so they are processed in the original input order
        for (int i = adj[u].size() - 1; i >= 0; i--) {
            int v = adj[u][i];

            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }

    cout << endl;
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

    DFS(start, adj);

    return 0;
}