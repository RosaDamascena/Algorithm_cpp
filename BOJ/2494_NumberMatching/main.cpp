// 2494 - 숫자 맞추기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    vector<array<int,10>> dp(N+1);
    vector<array<int,10>> prevMode(N+1);
    vector<array<int,10>> moveRot(N+1);
    for(int i=0;i<=N;i++){
        dp[i].fill(INF);
    }
    dp[0][0]=0;

    for(int i=0;i<N;i++){
        int orig = S[i]-'0';
        int want = T[i]-'0';
        for(int mode=0;mode<10;mode++){
            int curCost = dp[i][mode];
            if(curCost==INF) continue;
            int now = (orig + mode) % 10;
            int diff = (want - now + 10) % 10;
            // 1) 왼회전 diff
            {
                int nm = (mode + diff) % 10;
                int nc = curCost + diff;
                if(nc < dp[i+1][nm]){
                    dp[i+1][nm] = nc;
                    prevMode[i+1][nm] = mode;
                    moveRot[i+1][nm] = diff;
                }
            }
            // 2) 오른회전 (10-diff)
            int rd = (diff==0?0:10-diff);
            {
                int nm = mode;
                int nc = curCost + rd;
                if(nc < dp[i+1][nm]){
                    dp[i+1][nm] = nc;
                    prevMode[i+1][nm] = mode;
                    moveRot[i+1][nm] = -rd;
                }
            }
        }
    }
    
    int bestMode = 0, bestCost = INF;
    for(int m=0;m<10;m++){
        if(dp[N][m] < bestCost){
            bestCost = dp[N][m];
            bestMode = m;
        }
    }

    vector<pair<int,int>> ops;
    ops.reserve(N);
    int mode = bestMode;
    for(int i=N; i>0; i--){
        int r = moveRot[i][mode];
        ops.emplace_back(i, r);
        mode = prevMode[i][mode];
    }
    reverse(ops.begin(), ops.end());

    cout << bestCost << "\n";
    for(auto &p : ops){
        if(p.second!=0)
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}