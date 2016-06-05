#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nimSum = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        nimSum ^= ((m - 1) % 4) / 2;
    }
    cout << ((nimSum == 0) ? "Stannis" : "Daenerys") << endl;
    return 0;
}
