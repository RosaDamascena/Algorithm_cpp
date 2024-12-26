// 17298 - 오큰수
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> result(N, -1);
    stack<int> st;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        while (!st.empty() && A[st.top()] < A[i]) {
            result[st.top()] = A[i]; // 오큰수 저장
            st.pop();    
        }
        st.push(i); // 현재 인덱스를 스택에 추가
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}