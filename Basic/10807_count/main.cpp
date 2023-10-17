#include <iostream>
using namespace std;

int main() {
    int N, v;
    int arr[101];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> v;

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == v)
        {
            result++;
        }        
    }
    cout << result;
}
