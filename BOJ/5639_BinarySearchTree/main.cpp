// 5639 - 이진 검색 트리
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;      
int idx = 0;        

void postOrder(int lower, int upper) {
    if (idx >= pre.size()) return;
    
    int value = pre[idx];

    if (value < lower || value > upper) return;
    
    idx++;
    
    postOrder(lower, value);
    postOrder(value, upper);
    
    cout << value << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num;
    while(cin >> num) {
        pre.push_back(num);
    }
    
    postOrder(0, 1000001);
    
    return 0;
}
