// 7576 - 토마토(2차원)
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int M, N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int box[MAX][MAX];
queue<pair<int, int>> q;

int BFS(int unripeCnt) {
    int day = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || box[ny][nx]!= 0) continue;

            box[ny][nx] = box[y][x] + 1;
            q.push({ny, nx});
            day = max(day, box[ny][nx]);
            unripeCnt--;
        }
    }
    return (unripeCnt == 0) ? day - 1 : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    int unripeCnt = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> box[n][m];
            if (box[n][m] == 1) {
                q.push({n, m});
            } else if (box[n][m] == 0) {
                unripeCnt++;
            }
        }
    }

    if (unripeCnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int result = BFS(unripeCnt);
    cout << result << '\n';

    return 0;
}