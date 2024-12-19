// 15649 - N과 M(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited;

void DFS(int cnt) {
    if (cnt == M) {
        for (int num : arr) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr.push_back(i);
            DFS(cnt + 1);
            visited[i] = false;
            arr.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    visited.assign(N + 1, false);
    DFS(0);

    return 0;
}