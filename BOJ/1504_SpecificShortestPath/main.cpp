// 1504 - 특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1e15;

vector<pair<int,int>> graph[801];

vector<long long> dijkstra(int start, int N){
    vector<long long> dist(N+1, INF);
    dist[start] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        long long currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if(dist[currentNode] < currentCost) continue;

        for(auto &edge : graph[currentNode]){
            int nextNode = edge.first;
            long long nextCost = currentCost + edge.second;

            if(dist[nextNode] > nextCost){
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<long long> dist1 = dijkstra(1, N);
    vector<long long> distV1 = dijkstra(v1, N);
    vector<long long> distV2 = dijkstra(v2, N);

    long long route1 = dist1[v1] + distV1[v2] + distV2[N];
    long long route2 = dist1[v2] + distV2[v1] + distV1[N];

    long long answer = min(route1, route2);
    if(answer >= INF) answer = -1;

    cout << answer << "\n";
    return 0;
}
