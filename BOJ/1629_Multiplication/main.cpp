// 1629 - 곱셈
#include <iostream>
using namespace std;

long long modPow(long long a, long long b, long long c) {
    if (b == 0) return 1;

    long long half = modPow(a, b / 2, c);
    long long result = (half * half) % c;
    
    if (b % 2 == 1)
        result = (result * (a % c)) % c;
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << modPow(A, B, C) << "\n";
    
    return 0;
}