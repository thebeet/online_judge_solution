#include <iostream>
#include <cstring>

using namespace std;

long long N = 1000000;
bool primeFlag[1000010];
long long prime[500000];

int main() {
    memset(primeFlag, true, sizeof(primeFlag));
    int n = 0;
    for (long long i = 2; i <= N; ++i) {
        if (primeFlag[i]) {
            for (long long j = i * i; j <= N; j += i) {
                primeFlag[j] = false;
            }
            prime[n++] = i;
        }
    }

    long long f, t;
    cin >> f >> t;
    long long ans = t - f + 1;

    for (int i = 0; i < n; ++i) {
        long long k = prime[i];
        for (int j = 2; ; ++j) {
            k *= prime[i];
            if (k <= t) {
                if ((k >= f) && (primeFlag[j + 1])) {
                    ans -= 1;
                }
            } else {
                break;
            }
        }
    }


    cout << ans << endl;
    return 0;
}
