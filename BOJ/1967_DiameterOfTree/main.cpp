// 1967 - 트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> tree; 
bool visited[10001];               
int maxDist = 0;             
int farthestNode = 0;        

void DFS(int node, int distance) {
    visited[node] = true;

    if(distance > maxDist) {
        maxDist = distance;
        farthestNode = node;
    }
    
    for(auto &edge : tree[node]) {
        int nextNode = edge.first;
        int weight = edge.second;
        if(!visited[nextNode]) {
            DFS(nextNode, distance + weight);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    tree.resize(n + 1);
    
    for(int i = 0; i < n - 1; i++){
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }
    
    fill(visited, visited + n + 1, false);
    maxDist = 0;
    // 1번 노드로부터 가장 먼 노드 구하기
    DFS(1, 0);
    
    fill(visited, visited + n + 1, false);
    maxDist = 0;
    // 가장 먼 노드로부터 다시 가장 먼 노드 구하기
    DFS(farthestNode, 0);
    
    cout << maxDist << "\n";
    
    return 0;
}