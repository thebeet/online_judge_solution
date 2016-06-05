#include <iostream>

using namespace std;

int t[10010];

void add_prime_count(int m) {
    int tm = m;
    for (int j = 2; j * j <= tm; ++j) {
        while (tm % j == 0) {
            tm /= j;
            t[j] += 1;
        }
    }
    if (tm > 1) {
        t[tm] += 1;
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int m; 
        cin >> m;
        add_prime_count(m);
    }
    int ans = 1;
    for (int i = 1; i <= 10000; ++i) {
        ans *= (t[i] + 1);
        ans %= 10;
    }
    cout << ans << endl;
    return 0;
}
