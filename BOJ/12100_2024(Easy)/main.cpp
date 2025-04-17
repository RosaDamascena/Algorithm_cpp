// 12100 - 2048(Easy)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = 0;

vector<vector<int>> tilt(const vector<vector<int>>& board, int dir){
    vector<vector<int>> B = board;
    if(dir == 0){ // 상
        for(int c=0;c<N;c++){
            int target = 0;
            for(int r=0;r<N;r++){
                if(B[r][c]==0) continue;
                int v = B[r][c];
                B[r][c] = 0;
                if(B[target][c]==0){
                    B[target][c] = v;
                } else if(B[target][c]==v){
                    B[target][c] *= 2;
                    target++;
                } else {
                    target++;
                    B[target][c] = v;
                }
            }
        }
    } else if(dir == 1){ // 하
        for(int c=0;c<N;c++){
            int target = N-1;
            for(int r=N-1;r>=0;r--){
                if(B[r][c]==0) continue;
                int v = B[r][c];
                B[r][c] = 0;
                if(B[target][c]==0){
                    B[target][c] = v;
                } else if(B[target][c]==v){
                    B[target][c] *= 2;
                    target--;
                } else {
                    target--;
                    B[target][c] = v;
                }
            }
        }
    } else if(dir == 2){ // 좌
        for(int r=0;r<N;r++){
            int target = 0;
            for(int c=0;c<N;c++){
                if(B[r][c]==0) continue;
                int v = B[r][c];
                B[r][c] = 0;
                if(B[r][target]==0){
                    B[r][target] = v;
                } else if(B[r][target]==v){
                    B[r][target] *= 2;
                    target++;
                } else {
                    target++;
                    B[r][target] = v;
                }
            }
        }
    } else { // 우
        for(int r=0;r<N;r++){
            int target = N-1;
            for(int c=N-1;c>=0;c--){
                if(B[r][c]==0) continue;
                int v = B[r][c];
                B[r][c] = 0;
                if(B[r][target]==0){
                    B[r][target] = v;
                } else if(B[r][target]==v){
                    B[r][target] *= 2;
                    target--;
                } else {
                    target--;
                    B[r][target] = v;
                }
            }
        }
    }
    return B;
}

void dfs(int d, const vector<vector<int>>& board){
    for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
            answer = max(answer, board[r][c]);
    if(d==5) return;
    for(int dir=0; dir<4; dir++){
        auto B2 = tilt(board, dir);
        dfs(d+1, B2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << answer << "\n";
    return 0;
}
