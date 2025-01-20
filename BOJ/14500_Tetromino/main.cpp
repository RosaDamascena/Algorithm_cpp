// 14500 - 테트로미노
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int maxSum = 0;

// DFS를 이용해 'ㅗ' 모양 이외의 테트로미노 탐색
void DFS(int x, int y, int depth, int currentSum) {
    if (depth == 4) {
        maxSum = max(maxSum, currentSum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
            visited[nx][ny] = true;
            DFS(nx, ny, depth + 1, currentSum + grid[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

// 'ㅗ' 모양 탐색
void CalculateTShape(int x, int y) {
    int sum, nx, ny;
    for (int i = 0; i < 4; i++) {
        sum = grid[x][y];
        for (int dir = 0; dir < 4; dir++) {
            if (dir == i)
                continue;

            nx = x + dx[dir];
            ny = y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                sum += grid[nx][ny];
            }
        }

        maxSum = max(maxSum, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(i, j, 1, grid[i][j]);
            visited[i][j] = false;
            CalculateTShape(i, j);
        }
    }

    cout << maxSum << '\n';

    return 0;
}
