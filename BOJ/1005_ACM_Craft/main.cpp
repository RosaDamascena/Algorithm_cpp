// 1005 - ACM Craft
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        
        vector<int> buildTime(N+1);
        for(int i = 1; i <= N; i++){
            cin >> buildTime[i];
        }
        
        vector<vector<int>> graph(N+1);
        vector<int> indegree(N+1, 0);
        for(int i = 0; i < K; i++){
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            indegree[Y]++;
        }
        
        int target;
        cin >> target;
        
        // dp[i]: 건물 i를 완성하는 데 걸리는 최소 시간
        vector<int> dp(N+1, 0);
        queue<int> q;
        
        for(int i = 1; i <= N; i++){
            if(indegree[i] == 0){
                dp[i] = buildTime[i];
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next : graph[cur]){
                dp[next] = max(dp[next], dp[cur] + buildTime[next]);
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }
        
        cout << dp[target] << "\n";
    }
    
    return 0;
}
