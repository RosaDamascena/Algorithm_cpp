// 13549 - 숨바꼭질3
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
int N, K;
vector<int> dist(MAX, -1);

void Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (current == K) {
            cout << cost << '\n';
            break;
        }

        // 순간이동 (비용 0)
        if (current * 2 < MAX && (dist[current * 2] == -1 || cost < dist[current * 2])) {
            dist[current * 2] = cost;
            pq.push({cost, current * 2});
        }

        // 걷기 (비용 1)
        for (int next : {current - 1, current + 1}) {
            if (0 <= next && next < MAX && (dist[next] == -1 || cost + 1 < dist[next])) {
                dist[next] = cost + 1;
                pq.push({cost + 1, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> N >> K;
    Dijkstra(N);

    return 0;
}