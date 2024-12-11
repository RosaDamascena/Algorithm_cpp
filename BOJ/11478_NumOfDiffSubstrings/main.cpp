// 11478 - 서로 다른 부분 문자열의 개수
#include <iostream>
#include <set>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;

    set<string> substrings;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i+1; j <= s.length(); j++) {
            substrings.insert(s.substr(i, j-i)); // 부분 문자열 생성
        }
    }

    cout << substrings.size();
}