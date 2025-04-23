// 15681 - 트리와 쿼리
#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> adj;
vector<int> subtree_size;

void dfs(int u, int parent) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;
    adj.assign(N+1, {});
    subtree_size.assign(N+1, 0);

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R, 0);

    while (Q--) {
        int u;
        cin >> u;
        cout << subtree_size[u] << "\n";
    }

    return 0;
}
