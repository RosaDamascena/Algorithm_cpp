// 9935 - 문자열 폭발
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, bomb;
    cin >> s >> bomb;
    
    int bombSize = bomb.size();
    vector<char> st;

    for (char c : s) {
        st.push_back(c);
        
        if (st.size() >= bombSize) {
            bool match = true;
            for (int i = 0; i < bombSize; i++) {
                if (st[st.size() - bombSize + i] != bomb[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                for (int i = 0; i < bombSize; i++) {
                    st.pop_back();
                }
            }
        }
    }
    
    if (st.empty()) {
        cout << "FRULA";
    } else {
        for (char c : st) {
            cout << c;
        }
    }
    cout << "\n";
    
    return 0;
}