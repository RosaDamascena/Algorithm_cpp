// 15663 - N과 M(9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;       
vector<bool> visited;  
vector<int> seq;    

void DFS() {
    if(seq.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << seq[i] << (i == M - 1 ? "\n" : " ");
        }
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if(visited[i]) continue;

        if(i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])
            continue;
        
        visited[i] = true;
        seq.push_back(arr[i]);
        DFS();
        seq.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    visited.assign(N, false);
    
    DFS();
    
    return 0;
}