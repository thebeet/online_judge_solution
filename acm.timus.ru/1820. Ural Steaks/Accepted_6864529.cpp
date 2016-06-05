#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int t = ((n * 2 + k - 1) / k);
  if (t <= 2) {
    t = 2;
  }
  cout << t << endl;
  return 0;
}
