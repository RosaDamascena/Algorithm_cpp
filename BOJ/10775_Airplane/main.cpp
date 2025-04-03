// 10775 - 공항
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int G, P;
    cin >> G >> P;
    
    vector<int> parent(G + 1);
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }
    
    int result = 0;
    for (int i = 0; i < P; i++){
        int g;
        cin >> g;
        
        // g번 게이트까지 중에서 사용할 수 있는 가장 큰 번호를 찾음
        int availableGate = find(parent, g);
        if (availableGate == 0) break;
        
        // 갱신
        parent[availableGate] = find(parent, availableGate - 1);
        result++;
    }
    
    cout << result << "\n";
    return 0;
}