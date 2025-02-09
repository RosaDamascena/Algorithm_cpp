// 1916 - 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (int i = 0; i < M; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }
    
    int start, destination;
    cin >> start >> destination;
    
    const int INF = 1e9;
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty()){
        int currentCost = pq.top().first;
        int currentCity = pq.top().second;
        pq.pop();
        
        if(currentCost > dist[currentCity])
            continue;
        
        for(auto &edge : graph[currentCity]){
            int nextCity = edge.first;
            int nextCost = currentCost + edge.second;
            
            if(nextCost < dist[nextCity]){
                dist[nextCity] = nextCost;
                pq.push({nextCost, nextCity});
            }
        }
    }
    
    cout << dist[destination] << "\n";
    return 0;
}
