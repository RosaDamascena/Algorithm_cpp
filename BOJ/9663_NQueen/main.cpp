// 9663 - N-Queen
#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;
vector<int> visited;

bool Check(int n){
    for(int i=0; i<n; i++){
        // 같은 열에 있거나 대각선에 있는 경우
        if(visited[i] == visited[n] || abs(visited[i] - visited[n]) == n - i)
            return false;
    }
    return true;
}

void NQueen(int n){
    if(n == N){
        cnt++;
        return;
    }

    for(int i=0; i<N; i++){
        visited[n] = i;
        if(Check(n)){
            NQueen(n+1);
        }
    }
}

int main(){
    cin >> N;
    visited.assign(N, 0);

    NQueen(0);
    cout << cnt;

    return 0;
}