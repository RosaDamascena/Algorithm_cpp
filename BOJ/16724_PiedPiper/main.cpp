// 16724 - 피리 부는 사나이
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int NM = N * M;
    // state: 0 = unvisited, 1 = visiting, 2 = done
    vector<int> state(NM, 0);
    auto idx = [&](int r, int c){ return r * M + c; };

    auto next_idx = [&](int cur){
        int r = cur / M, c = cur % M;
        char d = A[r][c];
        if (d == 'U')      r--;
        else if (d == 'D') r++;
        else if (d == 'L') c--;
        else c++;   // R
        return idx(r, c);
    };

    int safe_zones = 0;
    vector<int> stk;
    stk.reserve(NM);

    for(int s = 0; s < NM; s++){
        if (state[s] != 0) continue;
        int cur = s;
        stk.clear();

        while(state[cur] == 0){
            state[cur] = 1;     // 탐색 중
            stk.push_back(cur);
            cur = next_idx(cur);
        }

        // 사이클 진입 여부 검사
        if (state[cur] == 1) {
            safe_zones++;
        }

        // 완료 표시
        for(int v : stk){
            state[v] = 2;
        }
    }

    cout << safe_zones << "\n";
    return 0;
}
