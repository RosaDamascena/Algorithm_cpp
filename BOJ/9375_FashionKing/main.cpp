// 9375 - 패션왕 신해빈
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes;

        for (int i = 0; i < n; i++) {
            string item, category;
            cin >> item >> category;
            clothes[category]++;
        }

        int combinations = 1;
        for (auto &c : clothes) {
            combinations *= (c.second + 1);
        }

        cout << combinations - 1 << '\n';
    }

    return 0;
}
