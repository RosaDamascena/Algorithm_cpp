// 2342 - Dance Dance Revolution
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int INF = 1e9;

int costMove(int u, int v){
    if(u == v) return 1;
    if(u == 0) return 2;
    // 인접
    if( (u==1&&v==2)||(u==2&&v==1) ||
        (u==2&&v==3)||(u==3&&v==2) ||
        (u==3&&v==4)||(u==4&&v==3) ||
        (u==4&&v==1)||(u==1&&v==4) )
        return 3;
    // 정반대
    return 4;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> seq;
    while(true){
        int x;
        cin >> x;
        if(x == 0) break;
        seq.push_back(x);
    }

    // dp[a][b] = 왼발 a, 오른발 b
    vector<vector<int>> dp(5, vector<int>(5, INF));
    dp[0][0] = 0;

    for(int step : seq){
        vector<vector<int>> newdp(5, vector<int>(5, INF));
        for(int a = 0; a < 5; a++){
            for(int b = 0; b < 5; b++){
                int cur = dp[a][b];
                if(cur == INF) continue;
                // 왼발을 움직여 step을 누르는 경우
                if(step != b){
                    int c = costMove(a, step);
                    newdp[step][b] = min(newdp[step][b], cur + c);
                }
                // 오른발을 움직여 step을 누르는 경우
                if(step != a){
                    int c = costMove(b, step);
                    newdp[a][step] = min(newdp[a][step], cur + c);
                }
            }
        }
        dp.swap(newdp);
    }

    int ans = INF;
    for(int a = 0; a < 5; a++)
        for(int b = 0; b < 5; b++)
            ans = min(ans, dp[a][b]);

    cout << ans << "\n";
    return 0;
}
