// 11779 - 최소비용 구하기2
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void dijkstra(int start, int n, const vector<vector<pair<int,int>>>& graph, 
              vector<int>& dist, vector<int>& parent) {
    dist.assign(n+1, INF);
    parent.assign(n+1, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curCost = cur.first;
        int u = cur.second;
        if(curCost > dist[u]) continue;
        for (int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < m; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }
    
    int start, end;
    cin >> start >> end;
    
    vector<int> dist, parent;
    dijkstra(start, n, graph, dist, parent);
    
    // 최소 비용 출력
    cout << dist[end] << "\n";
    
    vector<int> path;
    for (int cur = end; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    
    // 경로에 포함된 도시의 개수 출력
    cout << path.size() << "\n";
    
    // 경로 출력
    for (int city : path) {
        cout << city << " ";
    }
    cout << "\n";
    
    return 0;
}
