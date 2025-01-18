// 5525 - IOIOI
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int cnt = 0;
    int i = 0;
    while (i < M)
    {
        int temp = 0;
        if (S[i] == 'O')
        {
            i++;
            continue;
        }
        else
        {
            while (i + 2 < M && S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                temp++;
                if (temp >= N)
                {
                    cnt++;
                }
                i += 2;
            }
            i++;
        }
    }
    cout << cnt;

    return 0;
}
