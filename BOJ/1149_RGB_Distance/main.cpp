// 1149 - RGB 거리
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];
int rgb[1001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> rgb[i][j];
        }
    }

    dp[1][0] = rgb[1][0];
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]});
}