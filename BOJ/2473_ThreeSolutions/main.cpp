// 2473 - 세 용액
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    long long min_sum = 3e9 + 1;
    long long ans1 = 0, ans2 = 0, ans3 = 0;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            long long sum = A[i] + A[left] + A[right];

            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                ans1 = A[i];
                ans2 = A[left];
                ans3 = A[right];
            }

            if (sum < 0) left++;
            else right--;
        }
    }

    vector<long long> result = {ans1, ans2, ans3};
    sort(result.begin(), result.end());
    for (long long x : result) cout << x << " ";
}