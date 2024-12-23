//2579 - 계단 오르기
#include <iostream>
#include <vector>
using namespace std;

int staircase[300];
int dp[300];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> staircase[i];
    }

    dp[0] = staircase[0];
    if (n >= 2) {
        dp[1] = staircase[0] + staircase[1];
    }

    if (n >= 3) {
        dp[2] = max(staircase[0] + staircase[2], staircase[1] + staircase[2]);
    }

    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 2] + staircase[i], dp[i - 3] + staircase[i - 1] + staircase[i]);
    }

    cout << dp[n - 1];

    return 0;
}