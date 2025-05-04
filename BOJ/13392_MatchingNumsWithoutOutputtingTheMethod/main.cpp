// 13392 - 방법을 출력하지 않는 숫자 맞추기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string start, target;
    cin >> start >> target;

    vector<int> dp(10, INF), next_dp(10, INF);
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        fill(next_dp.begin(), next_dp.end(), INF);

        int orig = start[i] - '0';
        int want = target[i] - '0';
        for(int j = 0; j < 10; j++){
            if(dp[j] == INF) continue;
            int curr = (orig + j) % 10;
            int diff = (want - curr + 10) % 10;
            int nj = (j + diff) % 10;
            next_dp[nj] = min(next_dp[nj], dp[j] + diff);
            int costR = (10 - diff) % 10;
            next_dp[j] = min(next_dp[j], dp[j] + costR);
        }
        dp.swap(next_dp);
    }

    int answer = *min_element(dp.begin(), dp.end());
    cout << answer << "\n";
    return 0;
}