// 1918 - 후위 표기식
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string infix;
    cin >> infix;
    
    string postfix;       
    stack<char> st;            // 연산자를 저장할 스택

    for(char ch : infix) {
        if(isalpha(ch)) {
            // 알파벳은 그대로 후위 표기식에 추가
            postfix.push_back(ch);
        } else if(ch == '(') {
            st.push(ch);
        } else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            // '(' 제거
            if(!st.empty()) st.pop();
        } else {
            // 연산자인 경우
            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }
    
    // 남아있는 연산자들을 모두 후위 표기식에 추가
    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    
    cout << postfix << "\n";
    
    return 0;
}
