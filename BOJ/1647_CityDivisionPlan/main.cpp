// 1647 - 도시 분할 계획
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road {
    int houseA, houseB, cost;
};

int findRoot(int x, vector<int> &parent) {
    return parent[x] == x ? x : parent[x] = findRoot(parent[x], parent);
}

bool unite(int a, int b, vector<int> &parent, vector<int> &rank_) {
    a = findRoot(a, parent);
    b = findRoot(b, parent);
    if (a == b) return false;
    if (rank_[a] < rank_[b]) {
        parent[a] = b;
    } else {
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Road> roads;
    roads.reserve(M);
    for(int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        roads.push_back({A, B, C});
    }

    // 비용 오름차순 정렬
    sort(roads.begin(), roads.end(),
         [](const Road &r1, const Road &r2){
             return r1.cost < r2.cost;
         });

    // DSU 초기화
    vector<int> parent(N+1), rank_(N+1, 0);
    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    long long mstSum = 0;
    int maxEdgeInMST = 0;
    int edgesUsed = 0;

    for(const auto &r : roads){
        if (unite(r.houseA, r.houseB, parent, rank_)) {
            mstSum += r.cost;
            if (r.cost > maxEdgeInMST) 
                maxEdgeInMST = r.cost;
            edgesUsed++;
            if (edgesUsed == N-1) break;
        }
    }

    cout << (mstSum - maxEdgeInMST) << "\n";
    return 0;
}