// 5430 - AC
#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string p, array_input;
        int n;

        cin >> p >> n >> array_input;

        deque<int> dq;
        stringstream ss(array_input.substr(1, array_input.size() - 2));
        string temp;

        while (getline(ss, temp, ',')) {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
            }
        }

        bool is_reverse = false;
        bool error = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                is_reverse = !is_reverse;
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }

                if (is_reverse) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        if (error) {
            cout << "error\n";
        } else {
            cout << "[";
            if (is_reverse) {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                    if (it != dq.rbegin()) cout << ",";
                    cout << *it;
                }
            } else {
                for (auto it = dq.begin(); it != dq.end(); ++it) {
                    if (it != dq.begin()) cout << ",";
                    cout << *it;
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
