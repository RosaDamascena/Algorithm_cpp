// 7569 - 토마토
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, H;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dz[6] = {-1, 1, 0, 0, 0, 0};
vector<vector<vector<int>>> box;
queue<pair<pair<int, int>, int>> q;

int BFS(int unripeCnt) {
    int max_day = 0;

    while (!q.empty()) {
        auto front = q.front();
        int z = front.second;
        int y = front.first.first;
        int x = front.first.second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;

            if (box[nz][ny][nx] == 0) {
                box[nz][ny][nx] = box[z][y][x] + 1;
                q.push({{ny, nx}, nz});
                max_day = max(max_day, box[nz][ny][nx]);
                unripeCnt--;
            }
        }
    }

    // 익지 않은 토마토가 남아 있다면 -1 반환
    return (unripeCnt == 0) ? max_day - 1 : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N >> H;
    box.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));

    int unripeCnt = 0;    // 익지 않은 토마토 개수

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1) {
                    q.push({{n, m}, h});
                } else if (box[h][n][m] == 0) {
                    unripeCnt++;
                }
            }
        }
    }

    // 모든 토마토가 처음부터 익어있는 상태인 경우
    if (unripeCnt == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int result = BFS(unripeCnt);
    cout << result << '\n';

    return 0;
}
