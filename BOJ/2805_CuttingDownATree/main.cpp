// 2805 - 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    long long M;
    cin >> N >> M;
    
    vector<long long> trees(N);
    long long maxHeight = 0;
    for (int i = 0; i < N; i++){
        cin >> trees[i];
        maxHeight = max(maxHeight, trees[i]);
    }
    
    long long left = 0;
    long long right = maxHeight;
    long long result = 0;
    
    // 이분 탐색
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for (int i = 0; i < N; i++){
            if (trees[i] > mid)
                sum += (trees[i] - mid);
        }
        
        if(sum >= M){
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << result << "\n";
    return 0;
}
