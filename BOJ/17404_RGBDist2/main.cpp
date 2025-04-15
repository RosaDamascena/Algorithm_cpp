// 17404 - RGB거리2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // cost[i][c]: i번 집을 색 c로 칠하는 비용, c = 0(빨강), 1(초록), 2(파랑)
    vector<vector<int>> cost(N+1, vector<int>(3));
    for (int i = 1; i <= N; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    const int INF = 100000000;
    int answer = INF;
    
    for (int first = 0; first < 3; first++){
        vector<vector<int>> dp(N+1, vector<int>(3, INF));
        dp[1][first] = cost[1][first];
        
        for (int i = 2; i <= N; i++){
            dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        for (int color = 0; color < 3; color++){
            if (color == first)
                continue;
            answer = min(answer, dp[N][color]);
        }
    }
    
    cout << answer << "\n";
    return 0;
}
