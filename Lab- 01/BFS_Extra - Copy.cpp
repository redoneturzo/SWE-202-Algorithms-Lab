#include<bits/stdc++.h>
using namespace std;

void BFS(const vector<vector<int>>& adjecencyList, int start, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front(); //0
        q.pop();
        cout << current << " ";

        for (auto neighbor : adjecencyList[current]) { //{1, 2}, 
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    vector<vector<int>> adjecencyList = {
        {1, 2},        //node 0 is connected to nodes 1 and 2
        {0, 3, 4},     //node 1 is connected to nodes 0, 3, and 4
        {0, 5},        //node 2 is connected to nodes 0 and 5
        {1},           //node 3 is connected to node 1
        {1, 6},        //node 4 is connected to nodes 1 and 6
        {2},           //node 5 is connected to node 2
        {4}            //node 6 is connected to node 4
    };
    // for(int i=0;i<adjecencyList.size();i++){
    //     for(auto e:adjecencyList[i]){
    //         cout<<i<<" - "<<e<<endl;
    //     }
    // }

    vector<bool> visited(adjecencyList.size(), false);
    // for(int i=0;i<visited.size();i++){
    //     cout<<visited[i]<<endl;
    // }
    BFS(adjecencyList, 0, visited);
}


// #include <bits/stdc++.h>
// using namespace std;

// void BFS(const vector<vector<int>>& adjacencyList, int start, int target) {
//     vector<bool> visited(adjacencyList.size(), false);
//     vector<int> parent(adjacencyList.size(), -1);

//     queue<int> q;
//     q.push(start);
//     visited[start] = true;

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();

//         if (current == target)
//             break;

//         for (int neighbor : adjacencyList[current]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 parent[neighbor] = current;
//                 q.push(neighbor);
//             }
//         }
//     }

//     // Reconstruct path
//     vector<int> path;
//     for (int node = target; node != -1; node = parent[node]) {
//         path.push_back(node);
//     }

//     reverse(path.begin(), path.end());

//     // Print path
//     for (int node : path) {
//         cout << node << " ";
//     }
// }

// int main() {
//     vector<vector<int>> adjacencyList = {
//         {1, 2},
//         {0, 3, 4},
//         {0, 5},
//         {1},
//         {1, 6},
//         {2},
//         {4}
//     };

//     BFS(adjacencyList, 5, 4);

//     return 0;
// }
