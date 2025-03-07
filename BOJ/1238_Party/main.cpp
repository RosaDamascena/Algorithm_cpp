// 1238 - Party
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;  


void dijkstra(int start, const vector<vector<pair<int,int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int V = graph.size();
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curDist = cur.first;
        int curVertex = cur.second;
        
        if(curDist > dist[curVertex]) continue;
        
        for(auto &edge : graph[curVertex]){
            int nextVertex = edge.first;
            int weight = edge.second;
            if(dist[nextVertex] > dist[curVertex] + weight){
                dist[nextVertex] = dist[curVertex] + weight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, X;
    cin >> N >> M >> X;
    
    vector<vector<pair<int,int>>> graph(N+1), graph_rev(N+1);
    
    for(int i = 0; i < M; i++){
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
        graph_rev[v].push_back({u, t});
    }
    
    vector<int> dist_from_X(N+1, INF);
    vector<int> dist_to_X(N+1, INF);
    
    // 파티장 X에서 각 도시로 돌아가는 최단 거리
    dijkstra(X, graph, dist_from_X);
    // 각 도시에서 파티장 X로 가는 최단 거리
    dijkstra(X, graph_rev, dist_to_X);
    
    int answer = 0;

    for(int i = 1; i <= N; i++){
        answer = max(answer, dist_from_X[i] + dist_to_X[i]);
    }
    
    cout << answer << "\n";
    
    return 0;
}
