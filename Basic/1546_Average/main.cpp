#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a;
  int sum_N;

  for (int i = 0; i < N; i++)
  {
    cin >> a;
    sum_N += a;
  }
  cout << sum_N / N;
  return 0;
}