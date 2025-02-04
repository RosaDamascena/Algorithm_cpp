// 9251 - LCS
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    dp.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m];

    return 0;
}