// 9019 - DSLR
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAX = 10000;

void BFS(int A, int B) {
    vector<bool> visited(MAX, false);
    queue<pair<int, string>> q;

    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
        int current = q.front().first;
        string commands = q.front().second;
        q.pop();

        if (current == B) {
            cout << commands << '\n';
            return;
        }

        int D, S, L, R;
        // D 연산
        D = (2 * current) % MAX;
        if (!visited[D]) {
            visited[D] = true;
            q.push({D, commands + "D"});
        }

        // S 연산
        S = (current == 0) ? 9999 : current - 1;
        if (!visited[S]) {
            visited[S] = true;
            q.push({S, commands + "S"});
        }

        // L 연산
        L = (current % 1000) * 10 + current / 1000;
        if (!visited[L]) {
            visited[L] = true;
            q.push({L, commands + "L"});
        }

        // R 연산
        R = (current % 10) * 1000 + current / 10;
        if (!visited[R]) {
            visited[R] = true;
            q.push({R, commands + "R"});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        BFS(A, B);
    }

    return 0;
}
