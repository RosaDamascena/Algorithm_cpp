// 1753 - 최단경로
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);

void Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (auto &next : graph[current]) {
            int next_node = next.first;
            int next_cost = cost + next.second;

            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    Dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
