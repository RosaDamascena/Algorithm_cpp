// 17070 - 파이프 옮기기 1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));
    for (int r = 1; r <= N; r++){
        for (int c = 1; c <= N; c++){
            cin >> grid[r][c];
        }
    }
    
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(3, 0)));
    
    dp[1][2][0] = 1;

    for (int r = 1; r <= N; r++){
        for (int c = 1; c <= N; c++){
            if (grid[r][c] == 1) continue;

            // 가로 상태에서 이동
            if (dp[r][c][0] > 0) {
                // 오른쪽으로 이동
                if (c + 1 <= N && grid[r][c + 1] == 0) {
                    dp[r][c + 1][0] += dp[r][c][0];
                }
                // 대각선 이동
                if (r + 1 <= N && c + 1 <= N && grid[r][c + 1] == 0 &&
                    grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                    dp[r + 1][c + 1][1] += dp[r][c][0];
                }
            }
            
            // 대각선 상태에서 이동
            if (dp[r][c][1] > 0) {
                // 오른쪽 이동
                if (c + 1 <= N && grid[r][c + 1] == 0) {
                    dp[r][c + 1][0] += dp[r][c][1];
                }
                // 아래 이동
                if (r + 1 <= N && grid[r + 1][c] == 0) {
                    dp[r + 1][c][2] += dp[r][c][1];
                }
                // 대각선 이동
                if (r + 1 <= N && c + 1 <= N && grid[r][c + 1] == 0 &&
                    grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                    dp[r + 1][c + 1][1] += dp[r][c][1];
                }
            }
            
            // 세로 상태에서 이동
            if (dp[r][c][2] > 0) {
                // 아래 이동
                if (r + 1 <= N && grid[r + 1][c] == 0) {
                    dp[r + 1][c][2] += dp[r][c][2];
                }
                // 대각선 이동
                if (r + 1 <= N && c + 1 <= N && grid[r][c + 1] == 0 &&
                    grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                    dp[r + 1][c + 1][1] += dp[r][c][2];
                }
            }
        }
    }
    
    long long ans = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << ans << "\n";
    
    return 0;
}
