// 16946 - 벽 부수고 이동하기4
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>
using namespace std;

int N, M;
vector<string> grid;
vector<vector<int>> compId;
vector<int> compSize;   

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int start_i, int start_j, int id, int &count) {
    stack<pair<int, int>> s;
    s.push({start_i, start_j});
    compId[start_i][start_j] = id;
    
    while (!s.empty()) {
        auto [i, j] = s.top();
        s.pop();
        count++; 
        
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (grid[nx][ny] == '0' && compId[nx][ny] == 0) {
                compId[nx][ny] = id;
                s.push({nx, ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    compId.assign(N, vector<int>(M, 0));

    compSize.resize(N * M + 1, 0);
    int currentComp = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '0' && compId[i][j] == 0) {
                currentComp++;
                int count = 0;
                DFS(i, j, currentComp, count);
                compSize[currentComp] = count;
            }
        }
    }

    vector<string> result(N, string(M, '0'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '1') {
                int sum = 1;
                set<int> adjacentComps; 

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (grid[nx][ny] == '0') {
                        adjacentComps.insert(compId[nx][ny]);
                    }
                }

                for (int id : adjacentComps) {
                    sum += compSize[id];
                }
                result[i][j] = char((sum % 10) + '0');
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
