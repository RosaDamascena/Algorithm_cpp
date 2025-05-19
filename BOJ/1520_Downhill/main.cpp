// 1520 - 내리막길
#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> dp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    cin >> M >> N;
    map.assign(M, vector<int>(N));
    dp.assign(M, vector<int>(N, -1));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    cout << dfs(0, 0) << endl;
    return 0;
}