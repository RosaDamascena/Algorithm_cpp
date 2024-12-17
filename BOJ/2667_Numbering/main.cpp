// 2667 - 단지 번호 붙이기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<string> vec;             // 문자열로 입력받기
vector<vector<bool>> visited;   // 방문 여부 저장
vector<int> group;              // 각 단지의 크기 저장

void BFS(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[y][x] = true;
    int group_size = 0;

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        group_size++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && vec[ny][nx] == '1' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                que.push({nx, ny});
            }
        }
    }
    group.push_back(group_size);    // 단지 크기 저장
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vec.resize(N);                   
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    // BFS로 단지 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vec[i][j] == '1' && !visited[i][j]) {
                BFS(j, i); // 열(x), 행(y) 순서
            }
        }
    }

    sort(group.begin(), group.end());

    cout << group.size() << '\n'; // 총 단지 수 출력
    for (int size : group) {
        cout << size << '\n'; // 각 단지의 집의 수 출력
    }

    return 0;
}
