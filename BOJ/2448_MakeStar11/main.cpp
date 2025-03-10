// 2448 - 별 찍기 11
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> board;

void draw(int r, int c, int size) {
    if (size == 3) {
        board[r][c+2] = '*';
        board[r+1][c+1] = '*'; 
        board[r+1][c+3] = '*';
        board[r+2][c]   = '*'; 
        board[r+2][c+1] = '*'; 
        board[r+2][c+2] = '*'; 
        board[r+2][c+3] = '*'; 
        board[r+2][c+4] = '*';
        return;
    }
    int newSize = size / 2;

    draw(r, c + newSize, newSize);
    draw(r + newSize, c, newSize);
    draw(r + newSize, c + newSize * 2, newSize);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N; 
    int height = N;          
    int width = 2 * N - 1;     
    board.resize(height, string(width, ' ')); 
    
    draw(0, 0, N);
    
    for (int i = 0; i < height; i++){
        cout << board[i] << "\n";
    }
    return 0;
}
