// 11444 - 피보나치 수6
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

pair<long long, long long> Fibonacci(long long n) {
    if(n == 0)
        return {0, 1};
    
    auto p = Fibonacci(n / 2);
    long long a = p.first;   // F(n/2)
    long long b = p.second;  // F(n/2 + 1)
    
    long long twoB = (2 * b) % MOD;
    long long c = (a * ((twoB + MOD - a) % MOD)) % MOD;
    long long d = ((a * a) % MOD + (b * b) % MOD) % MOD;
    
    if(n % 2 == 0)
        return {c, d};
    else
        return {d, (c + d) % MOD};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    cout << Fibonacci(n).first % MOD << "\n";
    
    return 0;
}
