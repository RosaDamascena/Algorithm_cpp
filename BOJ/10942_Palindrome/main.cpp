// 10942 - 팰린드롬?
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    // dp[i][j] : i번째부터 j번째까지 수열이 팰린드롬이면 true, 아니면 false
    vector<vector<bool>> dp(N + 1, vector<bool>(N + 1, false));
    
    // 길이 1인 부분 수열은 항상 팰린드롬
    for (int i = 1; i <= N; i++){
        dp[i][i] = true;
    }
    
    // 길이가 2인 경우, 두 수가 같으면 팰린드롬
    for (int i = 1; i < N; i++){
        if(arr[i] == arr[i+1])
            dp[i][i+1] = true;
    }
    
    // 길이가 3 이상인 구간
    for (int len = 3; len <= N; len++){
        for (int i = 1; i <= N - len + 1; i++){
            int j = i + len - 1;
            if(arr[i] == arr[j] && dp[i+1][j-1])
                dp[i][j] = true;
        }
    }
    
    int M;
    cin >> M;
    while(M--){
        int S, E;
        cin >> S >> E;
        cout << (dp[S][E] ? 1 : 0) << "\n";
    }
    
    return 0;
}
