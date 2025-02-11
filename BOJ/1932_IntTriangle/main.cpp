// 1932 - 정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 501;
int N;
vector<vector<int>> triangle(MAX, vector<int>(MAX, 0));
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < N; i++) {   // 층수
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }

    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        maxSum = max(maxSum, dp[N - 1][i]);
    }
    cout << maxSum << '\n';

    return 0;
}