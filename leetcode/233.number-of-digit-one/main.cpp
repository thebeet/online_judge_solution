class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }

        int m = 1;
        int k = 1;
        while (n / m >= 10) {
            m *= 10;
            ++k;
        }
        int firstDigit = n / m;
        int r = n % m;

        int s = (k - 1) * (m / 10);

        if (firstDigit == 1) {
            return s + r + 1 + countDigitOne(r);
        } else {
            return s * firstDigit + m + countDigitOne(r);
        }
    }
};