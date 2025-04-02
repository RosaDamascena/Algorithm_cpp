// 2239 - 스도쿠
#include <iostream>
#include <string>
using namespace std;

int board[9][9];

bool isValid(int r, int c, int num) {
    // 같은 행 검사
    for (int j = 0; j < 9; j++) {
        if (board[r][j] == num) return false;
    }
    // 같은 열 검사
    for (int i = 0; i < 9; i++) {
        if (board[i][c] == num) return false;
    }
    // 해당 3×3 박스 검사
    int startRow = (r / 3) * 3;
    int startCol = (c / 3) * 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

// 백트래킹
bool solveSudoku() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == 0) { // 빈 칸 발견
                for (int num = 1; num <= 9; num++){
                    if (isValid(i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku()) return true;
                        board[i][j] = 0;
                    }
                }
                return false; // 어떤 숫자도 유효하지 않다면 실패
            }
        }
    }
    return true; // 모든 칸을 채웠다면 성공
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 9; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++){
            board[i][j] = s[j] - '0';
        }
    }
    
    solveSudoku();
    
    // 최종 보드 출력
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
