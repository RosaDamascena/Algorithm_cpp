// 17144 - 미세먼지 안녕!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, T;
vector<vector<int>> board;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int airUp, airDown;

// 미세먼지 확산
void diffuse() {
    vector<vector<int>> temp(R, vector<int>(C, 0));
    
    // 공기청정기 위치는 항상 -1
    temp[airUp][0] = -1;
    temp[airDown][0] = -1;
    
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if(board[i][j] == -1) continue;
            
            int amount = board[i][j];
            if(amount < 5) { 
                temp[i][j] += amount;
                continue;
            }

            int diff = amount / 5;
            int cnt = 0;

            for (int d = 0; d < 4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && board[nx][ny] != -1) {
                    temp[nx][ny] += diff;
                    cnt++;
                }
            }
            // 남은 미세먼지
            temp[i][j] += (amount - diff * cnt);
        }
    }
    board = temp;
}

// 미세먼지 이동 (공기청정기 작동)
void purify() {
    // 상단 공기청정기: 반시계방향 순환
    for (int i = airUp - 1; i > 0; i--) {
        board[i][0] = board[i-1][0];
    }
    for (int j = 0; j < C - 1; j++){
        board[0][j] = board[0][j+1];
    }
    for (int i = 0; i < airUp; i++){
        board[i][C-1] = board[i+1][C-1];
    }
    for (int j = C - 1; j >= 2; j--){
        board[airUp][j] = board[airUp][j-1];
    }
    board[airUp][1] = 0;

    // 하단 공기청정기: 시계방향 순환
    for (int i = airDown + 1; i < R-1; i++){
        board[i][0] = board[i+1][0];
    }
    for (int j = 0; j < C - 1; j++){
        board[R-1][j] = board[R-1][j+1];
    }
    for (int i = R - 1; i > airDown; i--){
        board[i][C-1] = board[i-1][C-1];
    }
    for (int j = C - 1; j >= 2; j--){
        board[airDown][j] = board[airDown][j-1];
    }
    board[airDown][1] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C >> T;
    board.resize(R, vector<int>(C));
    
    bool found = false;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) {
                if(!found) {
                    airUp = i;   
                    found = true;
                } else {
                    airDown = i;  
                }
            }
        }
    }
    
    for (int t = 0; t < T; t++){
        diffuse();    // 미세먼지 확산
        purify();     // 공기청정기 작동
    }
    
    // 남아있는 미세먼지의 총 합 계산 (공기청정기 칸은 제외)
    int answer = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if(board[i][j] > 0) {
                answer += board[i][j];
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
