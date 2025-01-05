// 2206 - 벽 부수고 이동하기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N, M;
vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

int BFS(int x, int y) {
    queue<pair<pair<pair<int, int>, int>, int>> q;
    q.push({{{x, y}, 1}, 0});   // 시작점: x, y, 거리 = 1, 벽 부수기 = 0
    visited[x][y][0] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int x = front.first.first.first;
        int y = front.first.first.second;
        int dist = front.first.second;
        int wall = front.second;


        if (x == N - 1 && y == M - 1) {
            return dist;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (map[nx][ny] == 1 && wall == 0) {
                visited[nx][ny][1] = true;  // 벽부수기 = 1
                q.push({{{nx, ny}, dist + 1}, 1});
            }
            else if (map[nx][ny] == 0 && !visited[nx][ny][wall]) {
                visited[nx][ny][wall] = true;
                q.push({{{nx, ny}, dist + 1}, wall});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    map.resize(N, vector<int>(M));
    visited.resize(N, vector<vector<bool>>(M, vector<bool>(2, false)));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    int result = BFS(0, 0);
    cout << result << '\n';
    
    return 0;
}