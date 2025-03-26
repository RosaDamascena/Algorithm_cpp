// 11053 - 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    vector<int> dp(N, 1);
    int answer = 1;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    
    cout << answer << "\n";
    return 0;
}
