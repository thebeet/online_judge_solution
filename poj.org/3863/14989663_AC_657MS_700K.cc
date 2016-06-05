#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int min_ans = 1000000000;
    for (int i = 0; i < m; ++i) {
        int u, d;
        cin >> u >> d;
        int lo, hi;
        lo = 0;
        hi = n;
        while (lo + 1 < hi) {
            int ans = (lo + hi) / 2;
            if (ans * u > (n - ans) * d) {
                hi = ans;
            } else {
                lo = ans;
            }
        }
        int ans = hi * u - (n - hi) * d;
        if (ans < min_ans) {
            min_ans = ans;
        }
    }
    cout << min_ans << endl;
    return 0;
}
