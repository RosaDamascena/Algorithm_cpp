// 14940 - 쉬운 최단거리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> map;
vector<vector<int>> dist;
queue<pair<int, int>> q;
int n, m;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> n >> m;

    map.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            } else if (map[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    BFS();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}