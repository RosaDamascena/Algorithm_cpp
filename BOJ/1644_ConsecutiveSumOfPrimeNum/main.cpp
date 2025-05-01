// 1644 - 소수의 연속합
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 1) 에라토스테네스의 체: 2와 N 사이의 소수 구하기
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    } 

    vector<int> primes;
    primes.reserve(N / 10);
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    // 2) 투 포인터
    int left = 0, right = 0;
    int sum = 0, ans = 0;
    int P = primes.size();

    while (true) {
        if (sum >= N) {
            if (sum == N) ans++;
            sum -= primes[left++];
        } else {
            if (right == P) break;
            sum += primes[right++];
        }
    }

    cout << ans << "\n";
    return 0;
}
