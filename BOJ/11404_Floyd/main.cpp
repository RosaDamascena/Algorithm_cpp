// 11404 - 플로이드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int INF = 1000000000; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> cost(n+1, vector<int>(n+1, INF));

    for (int i = 1; i <= n; i++){
        cost[i][i] = 0;
    }

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(cost[i][k] + cost[k][j] < cost[i][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(cost[i][j] == INF)
                cout << 0 << " ";
            else
                cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
