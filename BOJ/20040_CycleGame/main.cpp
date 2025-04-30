// 20040 - 사이클 게임
#include <iostream>
using namespace std;

static const int MAXN = 500000;
int parent[MAXN], depth_[MAXN];

int findRoot(int x) {
    // 루트 찾기
    int root = x;
    while (parent[root] != root) 
        root = parent[root];
    // x에서 올라오며 모두 root로 바로 연결
    while (parent[x] != x) {
        int next = parent[x];
        parent[x] = root;
        x = next;
    }
    return root;
}

// a, b 각자 대표 찾기
bool unionNodes(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return false;

    if (depth_[a] < depth_[b]) 
        parent[a] = b;
    else {
        parent[b] = a;
        if (depth_[a] == depth_[b]) 
            depth_[a]++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        depth_[i] = 0;
    }

    for (int turn = 1; turn <= m; turn++) {
        int u, v;
        cin >> u >> v;

        if (!unionNodes(u, v)) {
            cout << turn << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
    return 0;
}