// 1766 - 문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> indegree(N+1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0)
            pq.push(i);
    }

    vector<int> order;
    order.reserve(N);

    // 위상 정렬
    while (!pq.empty()) {
        int u = pq.top(); 
        pq.pop();
        order.push_back(u);
        // u를 푼 뒤, u → v로 연결된 문제들의 진입차수 감소
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << order[i];
    }
    cout << "\n";
    return 0;
}