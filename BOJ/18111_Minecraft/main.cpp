// 18111 - 마인크래프트
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M));
    int minHeight = 256, maxHeight = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
            minHeight = min(minHeight, land[i][j]);
            maxHeight = max(maxHeight, land[i][j]);
        }
    }

    // 정답 변수
    int minTime = 1e9;
    int optimalHeight = 0;

    for (int h = minHeight; h <= maxHeight; h++) {
        int time = 0;
        int inventory = B;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = land[i][j] - h;
                if (diff > 0) {
                    time += diff * 2;
                    inventory += diff;
                } else if (diff < 0) {
                    time -= diff;
                    inventory += diff;
                }
            }
        }

        if (inventory < 0) continue;

        if (time < minTime || (time == minTime && h > optimalHeight)) {
            minTime = time;
            optimalHeight = h;
        }
    }

    cout << minTime << " " << optimalHeight << "\n";

    return 0;
}
