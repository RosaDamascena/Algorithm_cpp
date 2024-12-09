// 24511 - queuestack
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    deque<int> queue;

    int  n, m, input;
    cin >> n;
    vector<int> isQueue(n);
    
    for(int i=0; i<n; i++) {
        cin >> isQueue[i];
    }

    for(int i=0; i<n; i++) {
        cin >> input;
        if(isQueue[i]==0)   // 0이면 큐, 1이면 스택
            queue.push_front(input);
    }
            
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> input;
        queue.push_back(input);
        cout << queue.front() << " ";
        queue.pop_front();
    } 
    
    return 0;
}
