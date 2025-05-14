// 1799 - 비숍
#include <iostream>
#include <vector>
using namespace std;

bool Backtracking(int u,
                  vector<bool> &visited,
                  const vector<vector<int>> &adj,
                  vector<int> &matchR) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        if (matchR[v] == -1 || Backtracking(matchR[v], visited, adj, matchR)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    int totalBishops = 0;
    int D = 2 * N - 1;  // 대각선 수

    // 칸 색깔(흑/백)별로 따로 계산
    for(int color = 0; color < 2; color++){
        vector<vector<int>> adj(D);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 1 && ((i+j)%2 == color)){
                    int diag1 = i + j;
                    int diag2 = i - j + (N - 1);
                    adj[diag1].push_back(diag2);
                }
            }
        }
        vector<int> matchR(D, -1);
        int matchCount = 0;
        // 모든 주대각선 u 에 대해 Backtracking 시도
        for(int u = 0; u < D; u++){
            vector<bool> visited(D, false);
            if(Backtracking(u, visited, adj, matchR))
                matchCount++;
        }
        totalBishops += matchCount;
    }

    cout << totalBishops << "\n";
    return 0;
}