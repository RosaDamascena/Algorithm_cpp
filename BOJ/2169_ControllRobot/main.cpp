// 2169 - 로봇 조종하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> dp(N, vector<int>(M, -1e9));
    
    dp[0][0] = grid[0][0];
    for (int j = 1; j < M; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    for (int i = 1; i < N; i++){
        vector<int> left(M, -1e9);
        left[0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < M; j++){
            left[j] = max(dp[i-1][j], left[j-1]) + grid[i][j];
        }
        
        vector<int> right(M, -1e9);
        right[M-1] = dp[i-1][M-1] + grid[i][M-1];
        for (int j = M - 2; j >= 0; j--){
            right[j] = max(dp[i-1][j], right[j+1]) + grid[i][j];
        }

        for (int j = 0; j < M; j++){
            dp[i][j] = max(left[j], right[j]);
        }
    }
    
    cout << dp[N-1][M-1] << "\n";
    return 0;
}
