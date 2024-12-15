// 1260 - DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v, x, y;
vector<vector<int>> vec;

void DFS(int start, vector<bool>& visited) {
    cout << start << ' ';
    visited[start] = true;
    for (int next : vec[start]) {
        if (!visited[next]) {
            DFS(next, visited);
        }
    }
}

void BFS(int start, vector<bool>& visited) {
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty()) {
        int now = que.front();
        que.pop();
        cout << now << ' ';
        for (int next : vec[now]) {
            if (!visited[next]) {
                que.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    vec.resize(n + 1); // 필요한 만큼 메모리 할당

    // 그래프 입력
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    // 각 노드의 인접 리스트를 정렬 (오름차순 방문을 위해)
    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    vector<bool> visited(n + 1, false);

    DFS(v, visited);
    cout << '\n';
    
    fill(visited.begin(), visited.end(), false);
    BFS(v, visited);

    return 0;
}