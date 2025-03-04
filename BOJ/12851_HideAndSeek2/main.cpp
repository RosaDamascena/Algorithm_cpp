// 12851 - 숨바꼭질 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000;

void BFS(int N, int K, vector<int>& dist, vector<int>& ways) {
    queue<int> q;
    dist[N] = 0;
    ways[N] = 1;
    q.push(N);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > MAX) continue;
            
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                ways[next] = ways[cur];
                q.push(next);
            }
            else if (dist[next] == dist[cur] + 1) {
                ways[next] += ways[cur];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> dist(MAX + 1, -1);
    vector<int> ways(MAX + 1, 0);
    
    BFS(N, K, dist, ways);
    
    cout << dist[K] << "\n" << ways[K] << "\n";
    
    return 0;
}
