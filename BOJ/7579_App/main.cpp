// 7579 - 앱
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> memory(N), cost(N);
    for (int i = 0; i < N; i++){
        cin >> memory[i];
    }
    for (int i = 0; i < N; i++){
        cin >> cost[i];
    }
    
    int maxCost = N * 100;
    vector<int> dp(maxCost + 1, 0);
    
    for (int i = 0; i < N; i++){
        for (int j = maxCost; j >= cost[i]; j--){
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }
    
    for (int c = 0; c <= maxCost; c++){
        if (dp[c] >= M){
            cout << c << "\n";
            break;
        }
    }
    
    return 0;
}
