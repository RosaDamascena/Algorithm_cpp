// 1865 - 웜홀
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TC;
    cin >> TC;
    
    while(TC--){
        int N, M, W;
        cin >> N >> M >> W;
        
        vector<Edge> edges;
        
        // 도로 정보
        for (int i = 0; i < M; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        
        // 웜홀 정보
        for (int i = 0; i < W; i++){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        
        vector<int> dist(N + 1, 0);
        bool negativeCycle = false;
        
        for (int i = 1; i <= N - 1; i++){
            for (auto &edge : edges){
                if (dist[edge.u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.w;
                }
            }
        }
        
        for (auto &edge : edges){
            if (dist[edge.u] + edge.w < dist[edge.v]) {
                negativeCycle = true;
                break;
            }
        }
        
        cout << (negativeCycle ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
