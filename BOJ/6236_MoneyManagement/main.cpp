// 6236 - 용돈 관리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> expense;

// K원을 인출했을 때, 인출 횟수가 M번 이하인지 확인
bool canWithdraw(int K) {
    int count = 1;         // 인출 횟수
    int money = K;         // 현재 가진 돈

    for (int i = 0; i < N; i++) {
        if (expense[i] > K) return false; // 하루치 지출이 K보다 크면 불가능

        if (money < expense[i]) {
            // 돈이 부족하면 다시 인출
            money = K;
            count++;
        }
        money -= expense[i];
    }

    return count <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    expense.resize(N);

    int maxExpense = 0, sumExpense = 0;

    for (int i = 0; i < N; i++) {
        cin >> expense[i];
        maxExpense = max(maxExpense, expense[i]); // 최저 인출 금액 후보
        sumExpense += expense[i]; // 최대 인출 금액 후보
    }

    int left = maxExpense;       // 최소한 하루 최대 지출보단 커야 함
    int right = sumExpense;      // 최대한 모든 돈을 한 번에 인출한 경우
    int answer = sumExpense;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canWithdraw(mid)) {
            // mid로도 가능하다면, 더 적은 돈으로도 가능한지 왼쪽 탐색
            answer = mid;
            right = mid - 1;
        } else {
            // mid로 부족하다면, 더 많은 돈 필요
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}