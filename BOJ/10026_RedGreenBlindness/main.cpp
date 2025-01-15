// 10026 - 적록색약
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int N;
vector<string> grid;
vector<vector<int>> visited;

void DFS(int x, int y, char color, bool isColorBlind) {
    visited[x][y] = 1;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0) {
            if (isColorBlind) {
                // 적록색약의 경우 R과 G를 동일하게 처리
                if ((color == 'R' || color == 'G') && (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
                    DFS(nx, ny, color, isColorBlind);
                } else if (grid[nx][ny] == color) {
                    DFS(nx, ny, color, isColorBlind);
                }
            } else {
                if (grid[nx][ny] == color) {
                    DFS(nx, ny, color, isColorBlind);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    grid.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int normalCount = 0;
    int colorBlindCount = 0;

    // 일반인의 경우
    visited.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                DFS(i, j, grid[i][j], false);
                normalCount++;
            }
        }
    }

    // 적록색약의 경우
    visited.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                DFS(i, j, grid[i][j], true);
                colorBlindCount++;
            }
        }
    }

    cout << normalCount << " " << colorBlindCount << "\n";

    return 0;
}