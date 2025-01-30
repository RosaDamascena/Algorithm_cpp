// 12865 - 평범한 배낭
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K+1, 0);

    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;

        for (int w = K; w >= W; w--) {  // 뒤에서부터 갱신
            dp[w] = max(dp[w], dp[w-W] + V);
        }
    }

    cout << dp[K] << "\n";
    return 0;
}
