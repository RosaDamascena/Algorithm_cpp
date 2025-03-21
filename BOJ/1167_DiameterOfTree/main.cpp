// 1167 - 트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<vector<pair<int,int>>> tree;

void DFS(int node, int dist, vector<bool>& visited, int &maxDist, int &farthestNode) {
    visited[node] = true;
    if(dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for(auto &edge : tree[node]) {
        int next = edge.first;
        int weight = edge.second;
        if(!visited[next]) {
            DFS(next, dist + weight, visited, maxDist, farthestNode);
        }
    }
}

pair<int,int> findFarthest(int start) {
    vector<bool> visited(V + 1, false);
    int maxDist = 0;
    int farthestNode = start;
    DFS(start, 0, visited, maxDist, farthestNode);
    return {farthestNode, maxDist};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> V;
    tree.resize(V + 1);

    for (int i = 0; i < V; i++){
        int node;
        cin >> node;
        while(true) {
            int next;
            cin >> next;
            if(next == -1) break;
            int weight;
            cin >> weight;
            tree[node].push_back({next, weight});
            tree[next].push_back({node, weight});
        }
    }
    
    pair<int,int> p = findFarthest(1);
    pair<int,int> q = findFarthest(p.first);
    
    cout << q.second << "\n";
    return 0;
}
