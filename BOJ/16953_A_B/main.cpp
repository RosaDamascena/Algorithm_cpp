// 16953 - A -> B
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B;
    cin >> A >> B;
    
    int count = 0;

    while(B > A) {
        if(B % 10 == 1) {      // B의 마지막 자리가 1이면 제거
            B = (B - 1) / 10;
            count++;
        } else if(B % 2 == 0) { // B가 2로 나누어 떨어지면 2로 나눔
            B /= 2;
            count++;
        } else {
            break;
        }
    }
    
    if(A == B)
        cout << count + 1 << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}
