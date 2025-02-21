// 1987 - 알파벳
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R, C;            
char board[21][21];    
int ans = 0;            

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dfs(int r, int c, int cnt, int mask) {
    ans = max(ans, cnt);
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        
        int letter = board[nr][nc] - 'A';
        
        // 이미 방문한 알파벳 건너뛰기
        if (mask & (1 << letter))
            continue;
        
        dfs(nr, nc, cnt + 1, mask | (1 << letter));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            board[i][j] = line[j];
        }
    }
    
    int initialMask = 0;
    initialMask |= (1 << (board[0][0] - 'A'));
    
    dfs(0, 0, 1, initialMask);
    
    cout << ans << "\n";
    
    return 0;
}
