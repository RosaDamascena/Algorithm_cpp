// 2467 - 용액
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long long> solutions(N);
    for (int i = 0; i < N; i++){
        cin >> solutions[i];
    }
    
    int left = 0;
    int right = N - 1;

    long long bestSum = 3e9;
    long long ans1 = 0, ans2 = 0;
    
    while (left < right) {
        long long sum = solutions[left] + solutions[right];
        
        if (llabs(sum) < llabs(bestSum)) {
            bestSum = sum;
            ans1 = solutions[left];
            ans2 = solutions[right];
        }
        
        // 합이 음수이면 left를 오른쪽으로 이동
        if (sum < 0) {
            left++;
        }
        // 합이 양수이면 right를 왼쪽으로 이동
        else {
            right--;
        }
    }
    
    cout << ans1 << " " << ans2 << "\n";
    
    return 0;
}
