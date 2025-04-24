// 1600 - 말이 되고픈 원숭이
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int y, x, k, d;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, W, H;
    cin >> K >> W >> H;
    vector<vector<int>> grid(H, vector<int>(W));
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            cin >> grid[i][j];

    // 말 움직임 8방향
    const int hy[8] = {-2,-2,-1,-1,1,1,2,2};
    const int hx[8] = {-1,1,-2,2,-2,2,-1,1};
    // 일반 이동 4방향
    const int dy[4] = {-1,1,0,0};
    const int dx[4] = {0,0,-1,1};

    vector<vector<vector<bool>>> visited(K+1,
        vector<vector<bool>>(H, vector<bool>(W,false)));

    queue<State> q;
    q.push({0,0,0,0});
    visited[0][0][0] = true;

    while(!q.empty()){
        auto s = q.front(); q.pop();
        // 목적지 도착
        if(s.y == H-1 && s.x == W-1){
            cout << s.d << "\n";
            return 0;
        }
        // 말처럼 움직이기
        if(s.k < K){
            for(int i = 0; i < 8; i++){
                int ny = s.y + hy[i], nx = s.x + hx[i];
                if(ny<0||ny>=H||nx<0||nx>=W) continue;
                if(grid[ny][nx]==1) continue;
                if(!visited[s.k+1][ny][nx]){
                    visited[s.k+1][ny][nx] = true;
                    q.push({ny, nx, s.k+1, s.d+1});
                }
            }
        }
        // 인접칸으로 움직이기
        for(int i = 0; i < 4; i++){
            int ny = s.y + dy[i], nx = s.x + dx[i];
            if(ny<0||ny>=H||nx<0||nx>=W) continue;
            if(grid[ny][nx]==1) continue;
            if(!visited[s.k][ny][nx]){
                visited[s.k][ny][nx] = true;
                q.push({ny, nx, s.k, s.d+1});
            }
        }
    }

    // 도달 불가
    cout << -1 << "\n";
    return 0;
}
