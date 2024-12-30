// 1654 - 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lanes;
int K, N;

long long BinarySearch(long long left, long long right) {
    long long mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += lanes[i] / mid;
        }

        if (cnt >= N) {
            left = mid + 1; // 더 긴 길이를 탐색
        } else {
            right = mid - 1; // 더 짧은 길이를 탐색
        }
    }
    return right; // 가능한 최대 길이
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> K >> N;
    lanes.resize(K);

    long long right = 0;
    for (int i = 0; i < K; i++) {
        cin >> lanes[i];
        right = max(right, (long long)lanes[i]);
    }

    long long result = BinarySearch(1, right);
    cout << result << '\n';

    return 0;
}