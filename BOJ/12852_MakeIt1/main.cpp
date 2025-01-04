// 12852 - 1로 만들기 2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> dp(N + 1);      // 최소 연산 횟수
    vector<int> before(N + 1);  // 이전 값 추적용

    dp[1] = 0;
    before[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[N] << '\n';

    // 경로 출력 (역추적)
    while (N > 0) {
        cout << N << ' ';
        N = before[N];
    }

    return 0;
}