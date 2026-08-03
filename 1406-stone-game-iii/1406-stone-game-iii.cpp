class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int current_sum = 0;
            int max_diff = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; ++k) {
                current_sum += stoneValue[i + k];
                int next_dp = dp[(i + k + 1) % 4];
                max_diff = max(max_diff, current_sum - next_dp);
            }

            dp[i % 4] = max_diff;
        }

        int result = dp[0];
        if (result > 0) return "Alice";
        if (result < 0) return "Bob";
        return "Tie";
    }
};