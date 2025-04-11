// 1197 - 최소 스패닝 트리(MST)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    int weight;
};

// 부모 찾기
int find(vector<int>& parent, int x) {
    if (parent[x] != x) 
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionNodes(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b)
        parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++){
        int A, B, C;
        cin >> A >> B >> C;
        edges[i] = {A, B, C};
    }
    
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });
    
    vector<int> parent(V + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    
    ll mstWeight = 0;
    
    for (int i = 0; i < E; i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].weight;
        if (find(parent, u) != find(parent, v)) {
            unionNodes(parent, u, v);
            mstWeight += w;
        }
    }
    
    cout << mstWeight << "\n";
    return 0;
}
