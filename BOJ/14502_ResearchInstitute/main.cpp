// 14502 - 연구소
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int answer = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(vector<vector<int>> board, const vector<pair<int,int>> &viruses) {
    int local_n = board.size();
    int local_m = board[0].size();
    queue<pair<int,int>> q;
    
    for (auto &v : viruses)
        q.push(v);
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < local_n && ny >= 0 && ny < local_m) {
                if (board[nx][ny] == 0) {
                    board[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int safe = 0;
    for (int i = 0; i < local_n; i++) {
        for (int j = 0; j < local_m; j++) {
            if (board[i][j] == 0)
                safe++;
        }
    }
    
    return safe;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    // 연구소 지도 입력: 0은 빈 칸, 1은 벽, 2는 바이러스
    vector<vector<int>> lab(n, vector<int>(m));
    vector<pair<int,int>> empties;  
    vector<pair<int,int>> viruses; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> lab[i][j];
            if (lab[i][j] == 0)
                empties.push_back({i, j});
            else if (lab[i][j] == 2)
                viruses.push_back({i, j});
        }
    }
    
    int emptyCount = empties.size();
    
    for (int i = 0; i < emptyCount; i++){
        for (int j = i + 1; j < emptyCount; j++){
            for (int k = j + 1; k < emptyCount; k++){
                vector<vector<int>> temp = lab;
                
                temp[empties[i].first][empties[i].second] = 1;
                temp[empties[j].first][empties[j].second] = 1;
                temp[empties[k].first][empties[k].second] = 1;

                int safe = BFS(temp, viruses);
                answer = max(answer, safe);
            }
        }
    }
    
    cout << answer << "\n";
    return 0;
}
