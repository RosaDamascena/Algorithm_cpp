// 2096 - 내려가기
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int dpMax[3], dpMin[3];

    cin >> dpMax[0] >> dpMax[1] >> dpMax[2];
    dpMin[0] = dpMax[0];
    dpMin[1] = dpMax[1];
    dpMin[2] = dpMax[2];

    for(int i = 2; i <= N; i++) {
        int row[3];
        cin >> row[0] >> row[1] >> row[2];

        int newDpMax[3], newDpMin[3];

        newDpMax[0] = row[0] + max(dpMax[0], dpMax[1]);
        newDpMin[0] = row[0] + min(dpMin[0], dpMin[1]);

        newDpMax[1] = row[1] + max({dpMax[0], dpMax[1], dpMax[2]});
        newDpMin[1] = row[1] + min({dpMin[0], dpMin[1], dpMin[2]});

        newDpMax[2] = row[2] + max(dpMax[1], dpMax[2]);
        newDpMin[2] = row[2] + min(dpMin[1], dpMin[2]);

        for(int c = 0; c < 3; c++) {
            dpMax[c] = newDpMax[c];
            dpMin[c] = newDpMin[c];
        }
    }

    int maxScore = max({dpMax[0], dpMax[1], dpMax[2]});
    int minScore = min({dpMin[0], dpMin[1], dpMin[2]});

    cout << maxScore << " " << minScore << "\n";
    return 0;
}
