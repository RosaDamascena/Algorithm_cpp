// 16236 - 아기 상어
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> board;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct Shark {
    int x, y; 
    int size;  
    int eaten; 
};

tuple<int,int,int> findFish(int sx, int sy, int sharkSize) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int,int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    
    int minDist = 1e9;
    int fishX = -1, fishY = -1;
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        int d = dist[x][y];
        
        if(d > minDist) continue;
        
        if(board[x][y] != 0 && board[x][y] < sharkSize) {
            if(d < minDist) {
                minDist = d;
                fishX = x;
                fishY = y;
            }
            else if(d == minDist) {
                if(x < fishX || (x == fishX && y < fishY)) {
                    fishX = x;
                    fishY = y;
                }
            }
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(dist[nx][ny] == -1 && board[nx][ny] <= sharkSize) {
                dist[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
    }
    
    if(fishX == -1) return {-1, -1, -1};
    else return {minDist, fishX, fishY};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    board.resize(N, vector<int>(N, 0));
    
    Shark shark;
    shark.size = 2;
    shark.eaten = 0;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                board[i][j] = 0;
            }
        }
    }
    
    int totalTime = 0;
    while (true) {
        auto [dist, fx, fy] = findFish(shark.x, shark.y, shark.size);
        if(dist == -1) break;
        
        totalTime += dist;
        shark.x = fx;
        shark.y = fy;
        board[fx][fy] = 0;
        shark.eaten++;
        
        if(shark.eaten == shark.size) {
            shark.size++;
            shark.eaten = 0;
        }
    }
    
    cout << totalTime << "\n";
    
    return 0;
}
