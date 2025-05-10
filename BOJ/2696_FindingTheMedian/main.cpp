// 2696 - 중앙값 구하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        int sequenceLength;
        cin >> sequenceLength;

        vector<int> medians;
        medians.reserve((sequenceLength + 1) / 2);

        // maxHeap에는 현재까지의 절반 이하(중앙값 포함)의 수를,
        // minHeap에는 그 나머지 절반 이상의 수를 담는다
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int index = 0; index < sequenceLength; index++) {
            int value;
            cin >> value;

            // 1) 새 값 삽입
            if (maxHeap.empty() || value <= maxHeap.top()) {
                maxHeap.push(value);
            } else {
                minHeap.push(value);
            }

            // 2) 두 힙의 크기 균형 맞추기
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            // 3) 홀수번째 입력마다 중앙값 기록
            if (index % 2 == 0) {
                medians.push_back(maxHeap.top());
            }
        }

        int medianCount = medians.size();
        cout << medianCount << "\n";

        for (int i = 0; i < medianCount; i++) {
            cout << medians[i];
            if ((i + 1) % 10 == 0 || i + 1 == medianCount)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}
