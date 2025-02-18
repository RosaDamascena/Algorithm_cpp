// 1043 - 거짓말
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int numTruth;
    cin >> numTruth;

    vector<bool> knowsTruth(N + 1, false);

    for(int i = 0; i < numTruth; i++){
        int p;
        cin >> p;
        knowsTruth[p] = true;
    }

    vector<vector<int>> parties(M);

    for(int i = 0; i < M; i++){
        int cnt;
        cin >> cnt;
        parties[i].resize(cnt);
        for(int j = 0; j < cnt; j++){
            cin >> parties[i][j];
        }
    }

    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < M; i++){
            bool mustTellTruth = false;
            // 파티 참가자 중 진실을 아는 사람이 있는지 확인
            for(int person : parties[i]){
                if(knowsTruth[person]) {
                    mustTellTruth = true;
                    break;
                }
            }

            if(mustTellTruth){
                for(int person : parties[i]){
                    if(!knowsTruth[person]) {
                        knowsTruth[person] = true;
                        changed = true;
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < M; i++){
        bool mustTellTruth = false;
        for(int person : parties[i]){
            if(knowsTruth[person]) {
                mustTellTruth = true;
                break;
            }
        }
        if(!mustTellTruth) answer++;
    }

    cout << answer << "\n";
    return 0;
}
