// 2178 - 미로 탐색
#include <iostream>
#include <queue>

using namespace std;
const int MAX = 101;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M;   // 미로 크기
char maze[MAX][MAX];    // 미로 2차원 배열
int visited[MAX][MAX];  // 방문 2차원 배열
int dist[MAX][MAX]; // 이동한 칸 기록 2차원 배열

void BFS(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = 1;
    dist[x][y] = 1;  // 시작점 1로 지정

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == '1' &&!visited[nx][ny]) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    BFS(0, 0);
    cout << dist[N-1][M-1];

    return 0;
}