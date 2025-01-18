// 7662 - 이중 우선순위 큐
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void Solve() {
    int k;
    cin >> k;

    priority_queue<int> maxHeap; // 최대 힙
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙
    unordered_map<int, int> count;

    while (k--) {
        char op;
        int n;
        cin >> op >> n;

        if (op == 'I') {
            maxHeap.push(n);
            minHeap.push(n);
            count[n]++;
        } else if (op == 'D') {
            if (n == 1) {
                // 최댓값 삭제
                while (!maxHeap.empty() && count[maxHeap.top()] == 0) {
                    maxHeap.pop();
                }
                if (!maxHeap.empty()) {
                    count[maxHeap.top()]--;
                    maxHeap.pop();
                }
            } else if (n == -1) {
                // 최솟값 삭제
                while (!minHeap.empty() && count[minHeap.top()] == 0) {
                    minHeap.pop();
                }
                if (!minHeap.empty()) {
                    count[minHeap.top()]--;
                    minHeap.pop();
                }
            }
        }
    }

    // 최종 결과 확인
    while (!maxHeap.empty() && count[maxHeap.top()] == 0) {
        maxHeap.pop();
    }
    while (!minHeap.empty() && count[minHeap.top()] == 0) {
        minHeap.pop();
    }

    if (maxHeap.empty() || minHeap.empty()) {
        cout << "EMPTY\n";
    } else {
        cout << maxHeap.top() << " " << minHeap.top() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        Solve();
    }

    return 0;
}
