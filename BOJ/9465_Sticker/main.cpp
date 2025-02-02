// 9465 - Sticker
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<vector<int>> sticker(2, vector<int>(n, 0));
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> sticker[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // dp[i][0] : i번째 열에서 아무 스티커도 선택하지 않은 경우의 최대 점수
        // dp[i][1] : i번째 열에서 위쪽 스티커를 선택한 경우의 최대 점수
        // dp[i][2] : i번째 열에서 아래쪽 스티커를 선택한 경우의 최대 점수
        dp[0][0] = 0;
        dp[0][1] = sticker[0][0];
        dp[0][2] = sticker[1][0];
 
        for (int i = 1; i < n; i++){
            dp[i][0] = max({ dp[i-1][0], dp[i-1][1], dp[i-1][2] });
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[0][i];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + sticker[1][i];
        }
 
        cout << max({ dp[n-1][0], dp[n-1][1], dp[n-1][2] }) << "\n";
    }
    
    return 0;
}