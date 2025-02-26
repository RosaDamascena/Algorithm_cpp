// 2565 - 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++){
        cin >> lines[i].first >> lines[i].second;
    }
    
    sort(lines.begin(), lines.end());
    
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (lines[j].second < lines[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int lis = 0;
    for (int i = 0; i < n; i++){
        lis = max(lis, dp[i]);
    }

    cout << n - lis << "\n";
    
    return 0;
}
