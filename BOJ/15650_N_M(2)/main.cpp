// 15650 - N과 M(2)
// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// 고른 수열은 오름차순이어야 한다.
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> combination;

void Backtrack(int start) {
    if (combination.size() == M) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        combination.push_back(i);
        Backtrack(i + 1);
        combination.pop_back();
    }
}

int main() {
    cin >> N >> M;
    Backtrack(1); 
    return 0;
}