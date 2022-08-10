class Solution {
public:
    int countBit(int n) {
        n = (n&0x55555555) + ((n>>1)&0x55555555);
        n = (n&0x33333333) + ((n>>2)&0x33333333);
        n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);
        n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff);
        n = (n&0x0000ffff) + ((n>>16)&0x0000ffff);
        return n;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long count[64];
        long long sum[64];
        memset(count, 0, sizeof(count));
        memset(sum, 0, sizeof(sum));
        std::sort(nums.begin(), nums.end());
        int before = -1;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (before == *it) {
                continue;
            }
            before = *it;
            count[countBit(*it)]++;
        }
        for (int i = 32; i >= 0; --i) {
            sum[i] = sum[i + 1] + count[i];
        }

        long long result = 0;
        for (int i = 0; i < 32; ++i) {
            if (k >= i) {
                result += count[i] * sum[k - i];
            } else {
                result += count[i] * sum[0];
            }

        }
        return result;
    }
};