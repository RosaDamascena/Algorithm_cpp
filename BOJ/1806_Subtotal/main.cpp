// 1806 - 부분합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	int start = 0, end = 0, sum = 0, minLen = 0x7FFFFFF;
	while (start <= end) {
		if (sum >= S) {
			minLen = min(minLen, end - start);
			sum -= arr[start++];
		}
		else if (end == N) break;
		else sum += arr[end++];
	}

	if (minLen == 0x7FFFFFF) cout << 0 << endl;
	else cout << minLen << endl;
	return 0;
}