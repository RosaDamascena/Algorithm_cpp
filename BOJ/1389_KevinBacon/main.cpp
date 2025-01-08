// 1389 - 케빈 베이컨의 6단계 법칙(플로이드-워셜 방식)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MAX = 101;

int N, M;
int dist[MAX][MAX];

void FloydWarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    FloydWarshall();

    int minKevinBacon = INF;
    int resultUser = -1;

    for (int i = 1; i <= N; i++) {
        int kevinBacon = 0;
        for (int j = 1; j <= N; j++) {
            kevinBacon += dist[i][j];
        }

        if (kevinBacon < minKevinBacon) {
            minKevinBacon = kevinBacon;
            resultUser = i;
        }
    }

    cout << resultUser << '\n';
    return 0;
}