// 2470 - 두 용액
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int left = 0, right = N - 1;
    long long best = 2000000001LL;
    long long sol1 = 0, sol2 = 0;
    
    while(left < right) {
        long long sum = arr[left] + arr[right];
        
        // 절댓값이 현재 best보다 작으면 갱신
        if (abs(sum) < best) {
            best = abs(sum);
            sol1 = arr[left];
            sol2 = arr[right];
        }
        
        // 합이 음수면 왼쪽 포인터 이동
        if(sum < 0) {
            left++;
        }
        // 합이 0 또는 양수면 오른쪽 포인터 이동
        else {
            right--;
        }
    }
    
    cout << sol1 << " " << sol2 << "\n";
    
    return 0;
}
