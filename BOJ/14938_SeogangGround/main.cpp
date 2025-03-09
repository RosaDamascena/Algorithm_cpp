// 14938 - 서강그라운드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
const int INF = 1e9;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<int> items(n+1);
    for (int i = 1; i <= n; i++){
        cin >> items[i];
    }
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    
    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = 1; j <= n; j++){
            if(dist[i][j] <= m)
                sum += items[j];
        }
        answer = max(answer, sum);
    }
    
    cout << answer << "\n";
    return 0;
}