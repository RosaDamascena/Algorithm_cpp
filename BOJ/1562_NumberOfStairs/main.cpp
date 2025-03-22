// 1562 - 계단 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // dp[len][d][mask]
    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));
    
    // 길이가 1인 경우 1부터 9까지만 가능
    for (int d = 1; d <= 9; d++){
        dp[1][d][1 << d] = 1;
    }
    
    for (int len = 1; len < N; len++){
        for (int d = 0; d < 10; d++){
            for (int mask = 0; mask < (1 << 10); mask++){
                if(dp[len][d][mask] == 0) continue;
                // 다음 숫자: d-1
                if(d > 0){
                    int nextd = d - 1;
                    int nextMask = mask | (1 << nextd);
                    dp[len+1][nextd][nextMask] = (dp[len+1][nextd][nextMask] + dp[len][d][mask]) % MOD;
                }
                // 다음 숫자: d+1
                if(d < 9){
                    int nextd = d + 1;
                    int nextMask = mask | (1 << nextd);
                    dp[len+1][nextd][nextMask] = (dp[len+1][nextd][nextMask] + dp[len][d][mask]) % MOD;
                }
            }
        }
    }
    
    long long answer = 0;
    int fullMask = (1 << 10) - 1;
    for (int d = 0; d < 10; d++){
        answer = (answer + dp[N][d][fullMask]) % MOD;
    }
    
    cout << answer << "\n";
    return 0;
}
