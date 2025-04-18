// 2166 - 다각현의 면적
#include <iostream> 
#include <vector>   
#include <cmath>     
#include <iomanip>  
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> x(N), y(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }

    // 신발끈 공식
    long long S = 0;
    for(int i = 0; i < N; i++){
        int j = (i + 1) % N;  
        S += x[i] * y[j] - x[j] * y[i];
    }

    double area = abs(S) / 2.0;
    // 소수점 첫째 자리까지 반올림 출력
    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}
