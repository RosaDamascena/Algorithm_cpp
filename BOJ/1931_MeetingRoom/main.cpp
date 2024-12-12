// 1931 - 회의실 배정
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {   // 끝나는 시간 기준으로 정렬
        cin >> meetings[i].second >> meetings[i].first;
    }

    sort(meetings.begin(), meetings.end());

    int end_time = 0;   // 끝나는 시간 기준
    int cnt = 0;    // 회의 개수
    for (int i = 0; i < N; i++) {
        if (meetings[i].second >= end_time) {
            end_time = meetings[i].first;   // 끝나는 시간 기준 갱신
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}