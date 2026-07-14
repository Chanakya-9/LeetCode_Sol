class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[201][201][201];

    int dfs(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size()) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        int ans = 0;


        ans = dfs(i + 1, g1, g2, nums);


        ans = (ans + dfs(i + 1,
                         g1 == 0 ? nums[i] : gcd(g1, nums[i]),
                         g2,
                         nums)) % MOD;

        ans = (ans + dfs(i + 1,
                         g1,
                         g2 == 0 ? nums[i] : gcd(g2, nums[i]),
                         nums)) % MOD;

        return dp[i][g1][g2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0, nums);
    }
};