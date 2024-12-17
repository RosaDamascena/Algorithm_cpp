// 1012 - 유기농 배추
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<int>> vec;

void BFS(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    vec[y][x] = 2;

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && vec[ny][nx] == 1) {
                vec[ny][nx] = 2;    // 방문 표시
                que.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        vec.assign(N, vector<int>(M, 0));   // 벡터 크기 재설정

        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            vec[y][x] = 1;
        }

        int cnt = 0;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (vec[n][m] == 1) {
                    BFS(m, n);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}