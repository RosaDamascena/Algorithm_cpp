// 1074 - Z
#include <iostream>
using namespace std;

int FindZ(int N, int r, int c){
    if (N == 0) return 0;

    int half = 1 << (N - 1);    // 비트 연산
    int quadrant = half * half;

    if (r < half && c < half) return FindZ(N - 1, r, c);    // 1사분면 (좌상)
    else if (r < half && c >= half) return quadrant + FindZ(N - 1, r, c - half);    // 2사분면 (우상)
    else if (r >= half && c < half) return 2 * quadrant + FindZ(N - 1, r - half, c);    // 3사분면 (좌하)
    else return 3 * quadrant + FindZ(N - 1, r - half, c - half);    // 4사분면 (우하)
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    cout << FindZ(N, r, c) << '\n';
    return 0;
}