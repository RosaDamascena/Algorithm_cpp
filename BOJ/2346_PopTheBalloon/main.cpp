// 2346 - 풍선 터뜨리기
#include <iostream>
#include <deque>

using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    deque<pair<int,int>> dq;

    cin >> N;

    int num;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        dq.push_back(make_pair(num,i));
    }

    while (!dq.empty()) {
        int now = dq.front().first; // 종이에 적힌 숫자 순서대로 확인
        cout << dq.front().second << " ";
        dq.pop_front();

        if (dq.empty()) {   // 덱이 비었으면 종료
            break;
        }

        if (now > 0) {  // 숫자가 양수일 때
            for (int i = 0; i < now - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }

        else {  // 숫자가 음수일 때
            for (int i = 0; i < -now; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}