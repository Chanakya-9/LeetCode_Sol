class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) return 0;
        if ((sum + target) % 2) return 0;

        int req = (sum + target) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = req; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[req];
    }
};