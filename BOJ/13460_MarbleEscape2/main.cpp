// 13460 - 구슬 탈출 2
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <array>
using namespace std;

int N, M;
vector<string> board;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> moveBall(int x, int y, int dx, int dy, int &count) {
    count = 0;
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
        count++;
        if (board[x][y] == 'O')
            break;
    }
    return {x, y};
}

int BFS(int startRx, int startRy, int startBx, int startBy) {
    bool visited[11][11][11][11] = {false};
    queue<array<int, 5>> q;
    q.push({startRx, startRy, startBx, startBy, 0});
    visited[startRx][startRy][startBx][startBy] = true;
    
    while (!q.empty()) {
        array<int, 5> s = q.front();
        q.pop();
        // s[4]: 지금까지의 이동 횟수
        if (s[4] >= 10)
            continue;
        
        for (int i = 0; i < 4; i++) {
            int nrx = s[0], nry = s[1];  // 빨간 구슬의 위치
            int nbx = s[2], nby = s[3];  // 파란 구슬의 위치
            int rCount = 0, bCount = 0;
            
            // 각 방향으로 빨간 구슬 이동
            auto redPos = moveBall(nrx, nry, dx[i], dy[i], rCount);
            nrx = redPos.first; 
            nry = redPos.second;
            // 각 방향으로 파란 구슬 이동
            auto bluePos = moveBall(nbx, nby, dx[i], dy[i], bCount);
            nbx = bluePos.first; 
            nby = bluePos.second;
            
            // 파란 구슬이 구멍에 빠지면 이 방향은 실패
            if (board[nbx][nby] == 'O')
                continue;

            // 빨간 구슬이 구멍에 빠졌다면 성공
            if (board[nrx][nry] == 'O')
                return s[4] + 1;
            
            // 두 구슬이 같은 위치에 있다면, 더 많이 이동한 구슬을 한 칸 뒤로 조정
            if (nrx == nbx && nry == nby) {
                if (rCount > bCount) {
                    nrx -= dx[i];
                    nry -= dy[i];
                } else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, s[4] + 1});
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++){
        cin >> board[i];
    }
    
    int rx, ry, bx, by;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (board[i][j] == 'R') {
                rx = i; ry = j;
            }
            if (board[i][j] == 'B') {
                bx = i; by = j;
            }
        }
    }
    
    cout << BFS(rx, ry, bx, by) << "\n";
    
    return 0;
}
