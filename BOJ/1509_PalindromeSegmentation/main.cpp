// 1509 - 팰린드롬 분할
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = i;  
    }

    for(int center = 0; center < n; center++){
        // 홀수
        int l = center, r = center;
        while(l >= 0 && r < n && S[l] == S[r]){
            dp[r+1] = min(dp[r+1], dp[l] + 1);
            l--; r++;
        }

        // 짝수
        l = center; 
        r = center + 1;
        while(l >= 0 && r < n && S[l] == S[r]){
            dp[r+1] = min(dp[r+1], dp[l] + 1);
            l--; r++;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}