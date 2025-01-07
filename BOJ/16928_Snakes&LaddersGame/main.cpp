// 16928 - 뱀과 사다리 게임
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 101;

int N, M;
vector<int> board(MAX);

int BFS() {
    queue<int> q;
    vector<int> dist(MAX, -1);
    dist[1] = 0; 
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == 100) return dist[now];

        for (int i = 1; i <= 6; i++) {
            int next = now + i;

            if (next > 100) continue;

            next = board[next];
            if (dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    // 사다리 정보 입력
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        board[a] = b;
    }

    // 뱀 정보 입력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        board[a] = b;
    }

    cout << BFS() << '\n';

    return 0;
}
