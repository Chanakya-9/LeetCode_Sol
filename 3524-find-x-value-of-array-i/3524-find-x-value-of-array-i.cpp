class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> nxt(k, 0);
            int m = x % k;
            nxt[m] = 1;

            for (int i = 0; i < k; i++) {
                if (dp[i] > 0) {
                    nxt[(i * m) % k] += dp[i];
                }
            }

            for (int i = 0; i < k; i++) {
                ans[i] += nxt[i];
            }

            dp = move(nxt);
        }

        return ans;
    }
};