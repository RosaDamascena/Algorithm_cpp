// 9328 - 열쇠
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(vector<string>& map, vector<bool>& keys) {
    int H = map.size();      // 확장된 지도 높이 (원래 h+2)
    int W = map[0].size();   // 확장된 지도 너비 (원래 w+2)
    int docCnt = 0;        // 얻은 문서 개수

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<pair<int,int>>> door(26);

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (visited[nx][ny]) continue;

            char cell = map[nx][ny];
            if (cell == '*') continue;

            visited[nx][ny] = true;

            if (cell == '$') { 
                // 문서 발견: 개수 증가한 후, 해당 칸은 빈 공간으로 처리
                docCnt++;
                map[nx][ny] = '.';
                q.push({nx, ny});
            } else if (islower(cell)) { 
                // 열쇠 발견 (소문자)
                int idx = cell - 'a';
                if (!keys[idx]) {
                    keys[idx] = true;
                    // 이 열쇠로 열 수 있는 모든 문(대문자)을 큐에 넣는다.
                    for (auto pos : door[idx]) {
                        q.push(pos);
                    }
                    door[idx].clear();
                }
                // 열쇠가 있는 칸은 빈 공간으로 처리하고 탐색 지속
                map[nx][ny] = '.';
                q.push({nx, ny});
            } else if (isupper(cell)) { 
                // 문 발견 (대문자)
                int idx = cell - 'A';
                if (keys[idx]) {
                    map[nx][ny] = '.';
                    q.push({nx, ny});
                } else {
                    // 열쇠가 없다면, 나중에 열 수 있도록 해당 좌표 저장
                    door[idx].push_back({nx, ny});
                }
            } else {
                // 빈 공간('.')인 경우
                q.push({nx, ny});
            }
        }
    }
    
    return docCnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int h, w;
        cin >> h >> w;
        
        // 지도 외부에 한 겹의 빈 공간('.')을 둘러서 확장
        vector<string> map(h + 2, string(w + 2, '.'));
        for (int i = 1; i <= h; i++){
            string s;
            cin >> s;
            for (int j = 1; j <= w; j++){
                map[i][j] = s[j-1];
            }
        }
        
        string initKeys;
        cin >> initKeys;
        vector<bool> keys(26, false);
        if (initKeys != "0") {
            for (char k : initKeys) {
                keys[k - 'a'] = true;
            }
        }
        
        int result = BFS(map, keys);
        cout << result << "\n";
    }
    
    return 0;
}
