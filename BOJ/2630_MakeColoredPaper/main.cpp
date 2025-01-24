// 2630 - 색종이 만들기
#include <iostream>
#include <vector>
using namespace std;

int whiteCnt = 0;
int blueCnt = 0;

bool isSame(const vector<vector<int>>& paper, int x, int y, int size) {
    int color = paper[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

void divideAndConquer(const vector<vector<int>>& paper, int x, int y, int size) {
    if (isSame(paper, x, y, size)) {
        if (paper[x][y] == 0) {
            whiteCnt++;
        } else {
            blueCnt++;
        }
        return;
    }

    int newSize = size / 2;
    divideAndConquer(paper, x, y, newSize);             // 1번 영역
    divideAndConquer(paper, x, y + newSize, newSize);  // 2번 영역
    divideAndConquer(paper, x + newSize, y, newSize);  // 3번 영역
    divideAndConquer(paper, x + newSize, y + newSize, newSize); // 4번 영역
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    
    divideAndConquer(paper, 0, 0, N);

    cout << whiteCnt << "\n";
    cout << blueCnt << "\n";

    return 0;
}
