// 11660 - 구간 합 구하기 5
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> arr[i][j];
        }
    }
    
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 
                     - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = dp[x2][y2] - dp[x1 - 1][y2] 
                   - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << result << "\n";
    }
    
    return 0;
}