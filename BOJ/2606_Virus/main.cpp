// 2606 - 바이러스
#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
int cnt = 0;
vector<int> arr[101];

void DFS(int start, vector<bool>& visited) {
    visited[start] = true;
    for (int next : arr[start]) {
        if (!visited[next]) {
            cnt++;
            DFS(next, visited);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    DFS(1, visited);

    cout << cnt;
    return 0;
}