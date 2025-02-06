// 15686 - 치킨 배달
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int N, M;
int ans = 1e9;

// start: 조합에 추가할 치킨집 인덱스의 시작 위치
// selected: 현재 선택한 치킨집의 인덱스들
void selectChicken(int start, vector<int>& selected) {
    if (selected.size() == M) {
        int totalDistance = 0;
        for (int i = 0; i < houses.size(); i++) {
            int houseR = houses[i].first; 
            int houseC = houses[i].second;
            int minDist = 1e9;
            for (int j = 0; j < selected.size(); j++) {
                int chickenR = chickens[selected[j]].first; 
                int chickenC = chickens[selected[j]].second;
                int dist = abs(houseR - chickenR) + abs(houseC - chickenC);
                minDist = min(minDist, dist);
            }
            totalDistance += minDist;
        }
        ans = min(ans, totalDistance);
        return;
    }

    
    // 가능한 치킨집 조합
    for (int i = start; i < chickens.size(); i++) {
        selected.push_back(i);
        selectChicken(i + 1, selected);
        selected.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int cell;
            cin >> cell;
            if (cell == 1) {
                houses.push_back({i, j});
            } else if (cell == 2) {
                chickens.push_back({i, j});
            }
        }
    }
    
    vector<int> selected;
    selectChicken(0, selected);
    
    cout << ans << "\n";
    return 0;
}
