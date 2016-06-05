#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n > 198) {
		cout << 0 << endl;
	} else {
		cout << 100 - abs(n - 99) << endl;
	}
	return 0;
}
