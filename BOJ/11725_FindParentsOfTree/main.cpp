// 11725 - 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFS(const vector<vector<int>> &tree, int N) {
    vector<int> parent(N + 1, 0);    
    vector<bool> visited(N + 1, false);   
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : tree[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
    return parent;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<vector<int>> tree(N + 1);
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    vector<int> parent = BFS(tree, N);
    
    for (int i = 2; i <= N; i++){
        cout << parent[i] << "\n";
    }
    
    return 0;
}
