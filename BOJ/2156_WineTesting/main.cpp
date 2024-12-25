// 2156 - 포도주 시식
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> wine(10001, 0);
vector<int> dp(10001, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = max({wine[1] + wine[2], wine[1] + wine[3], wine[2] + wine[3]});

    for (int i = 4; i <= N; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]});
    }

    cout << dp[N] << '\n';

    return 0;
}