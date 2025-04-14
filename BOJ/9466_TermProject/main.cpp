// 9466 - 텀 프로젝트
#include <iostream>
#include <vector>
using namespace std;

int n;             
vector<int> arr;          
vector<bool> visited;      
vector<bool> finished;    
int cycleCount;          

void dfs(int cur) {
    visited[cur] = true;      
    int next = arr[cur];       

    if (!visited[next])
        dfs(next);

    else {
        if (!finished[next]) {
            for (int temp = next; temp != cur; temp = arr[temp])
                cycleCount++;
            cycleCount++;
        }
    }
    finished[cur] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;   
    cin >> T;
    while (T--) {
        cin >> n;
        arr.assign(n + 1, 0);
        visited.assign(n + 1, false);
        finished.assign(n + 1, false);
        cycleCount = 0;
        
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        
        for (int i = 1; i <= n; i++){
            if (!visited[i])
                dfs(i);
        }

        cout << n - cycleCount << "\n";
    }
    
    return 0;
}
