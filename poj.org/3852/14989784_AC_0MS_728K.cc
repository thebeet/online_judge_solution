#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while ((cin >> n) && n > 0) {
        vector<string> input(n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
            reverse(input[i].begin(), input[i].end());
        }
        sort(input.begin(), input.end());
        int ans = input[0].size() - 1;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, int(input[i].size() - 1));
            if (input[i - 1].size() == input[i].size()) {
                int match = 0;
                while (input[i - 1][match] == input[i][match]) {
                    match++;
                    if (match >= input[i - 1].size() || match >= input[i].size()) {
                        break;
                    }
                }
                ans = min(ans, max(0, min((int)input[i - 1].size() - match - 1, (int)input[i].size() - match - 1)));
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}
