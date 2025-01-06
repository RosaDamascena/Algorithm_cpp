// 1697 - 숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
int N, K;
int dist[MAX];

void BFS() {
    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (now == K) {
            cout << dist[now] << '\n';
            return;
        }
        for (int next : {now - 1, now + 1, 2 * now}) {
            if (0 <= next && next <= MAX - 1 &&!dist[next]) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    BFS();
    return 0;
}