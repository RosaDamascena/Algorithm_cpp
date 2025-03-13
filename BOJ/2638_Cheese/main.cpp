// 2638 - 치즈
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int R, C, T;
vector<vector<int>> board;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 외부 공기 표시
void DFS(int x, int y, vector<vector<bool>> &ext, vector<vector<bool>> &visited) {
    visited[x][y] = true;
    ext[x][y] = true;
    for (int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (!visited[nx][ny] && board[nx][ny] == 0) {
            DFS(nx, ny, ext, visited);
        }
    }
}

// 치즈 녹이기
int meltCheese(const vector<vector<bool>> &ext) {
    int meltCnt = 0;
    vector<pair<int,int>> meltList;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (board[i][j] == 1) {  // 치즈인 경우
                int cnt = 0;
                for (int d = 0; d < 4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (ext[nx][ny]) cnt++;
                }
                if (cnt >= 2) {  // 외부 공기와 2면 이상 접촉한 경우 녹임
                    meltList.push_back({i, j});
                }
            }
        }
    }
    for (auto &p : meltList) {
        board[p.first][p.second] = 0;
        meltCnt++;
    }
    return meltCnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    board.resize(R, vector<int>(C, 0));
    
    int totalCheese = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> board[i][j];
            if (board[i][j] == 1) {
                totalCheese++;
            }
        }
    }
    
    T = 0;  // 치즈가 녹는 시간
    while (totalCheese > 0) {
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<bool>> ext(R, vector<bool>(C, false));
        
        DFS(0, 0, ext, visited);
        
        int melted = meltCheese(ext);
        totalCheese -= melted;

        T++;
    }
    
    cout << T << "\n";
    return 0;
}