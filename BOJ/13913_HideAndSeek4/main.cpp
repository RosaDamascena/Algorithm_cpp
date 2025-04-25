// 13913 - 숨바꼭질 4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAX_POS = 100000;

void BFS(int start, int target, vector<int>& dist, vector<int>& parent) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int x = q.front(); 
        q.pop();
        if (x == target) 
            break;

        int moves[3] = { x - 1, x + 1, x * 2 };
        for (int i = 0; i < 3; i++) {
            int nx = moves[i];
            if (nx < 0 || nx > MAX_POS) 
                continue;
            if (dist[nx] != -1) 
                continue;

            dist[nx] = dist[x] + 1;
            parent[nx] = x;
            q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX_POS + 1, -1), parent(MAX_POS + 1, -1);

    BFS(N, K, dist, parent);

    // 최단 시간 출력
    cout << dist[K] << "\n";

    vector<int> path;
    for (int cur = K; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    // 뒤집어서 출력
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i] << (i ? ' ' : '\n');
    }

    return 0;
}
