#include <iostream>
using namespace std;

int main() {
  int N;
  int M = -1;
  cin >> N;
  int score;
  int sum = 0;
  float answer;

  for (int i = 0; i < N; i++) {
    cin >> score;
    sum += score;
    if (score > M) {
      M = score;
    }
  }

  answer = sum * 100.0 / M / N;
  cout << answer;

  return 0;
}