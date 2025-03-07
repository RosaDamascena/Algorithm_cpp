// 1707 - 이분 그래프
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(int start, const vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (color[next] == 0) {
                color[next] = -color[cur];
                q.push(next);
            }
            else if (color[next] == color[cur]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; 
    cin >> K;
    
    while(K--){
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> graph(V + 1);
        for (int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> color(V + 1, 0);
        bool bipartite = true;
        
        for (int i = 1; i <= V && bipartite; i++){
            if (color[i] == 0) {
                if (!BFS(i, graph, color)) {
                    bipartite = false;
                    break;
                }
            }
        }
        
        cout << (bipartite ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
