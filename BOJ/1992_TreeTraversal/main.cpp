// 1991 - 트리 순회
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 트리를 저장하기 위한 구조체
map<char, pair<char, char>> tree;

void PreorderTraversal(char node) { // 부모 노드 -> 왼쪽 자식 -> 오른쪽 자식
    if (node == '.') return;
    cout << node;
    PreorderTraversal(tree[node].first);
    PreorderTraversal(tree[node].second);
}

void InorderTraversal(char node) {  // 왼쪽 자식 -> 부모 노드 -> 오른쪽 자식
    if (node == '.') return;
    InorderTraversal(tree[node].first); 
    cout << node;
    InorderTraversal(tree[node].second);
}

void PostorderTraversal(char node) {    // 왼쪽 자식 -> 오른쪽 자식 -> 부모 노드
    if (node == '.') return;
    PostorderTraversal(tree[node].first); 
    PostorderTraversal(tree[node].second);
    cout << node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent] = {left, right}; // 부모-자식 관계 저장
    }

    PreorderTraversal('A');
    cout << '\n';
    InorderTraversal('A');
    cout << '\n';
    PostorderTraversal('A');
    cout << '\n';

    return 0;
}
