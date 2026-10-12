class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> bit_count(31, 0);

        for (int x : nums) {
            for (int bit = 0; bit < 31; ++bit) {
                if ((x >> bit) & 1) {
                    bit_count[bit]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int bit = 0; bit < 31; ++bit) {
                if (bit_count[bit] > 0) {
                    val |= (1LL << bit);
                    bit_count[bit]--;
                }
            }
            ans = (ans + val * val) % MOD;
        }

        return ans;
    }
};