// 1991 - 트리 순회(연결 리스트 기반 트리)
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node(); // 동적으로 메모리 할당
    newNode->data = data;   // 데이터 설정
    newNode->left = nullptr;   // 초기화
    newNode->right = nullptr;
    return newNode; // 생성된 노드의 주소 반환
}

void Preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data;
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root) {
    if (root == nullptr) return;
    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}

void Postorder(Node* root) {
    if (root == nullptr) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data;
}

int sub() {
    int N;
    cin >> N;

    Node* nodes[26] = {nullptr}; // A-Z에 해당하는 노드 배열

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;

        if (nodes[parent - 'A'] == nullptr)
            nodes[parent - 'A'] = createNode(parent);

        if (left != '.') {
            nodes[left - 'A'] = createNode(left);
            nodes[parent - 'A']->left = nodes[left - 'A'];
        }

        if (right != '.') {
            nodes[right - 'A'] = createNode(right);
            nodes[parent - 'A']->right = nodes[right - 'A'];
        }
    }

    Preorder(nodes['A' - 'A']);
    cout << '\n';
    Inorder(nodes['A' - 'A']);
    cout << '\n';
    Postorder(nodes['A' - 'A']);
    cout << '\n';

    return 0;
}
