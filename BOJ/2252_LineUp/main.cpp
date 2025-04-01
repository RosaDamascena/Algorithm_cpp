// 2252 - 줄 세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    
    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++){
        if (indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int nxt : graph[cur]){
            if (--indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    
    for (int num : result)
        cout << num << " ";
        
    return 0;
}
