class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];

        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for (int m = i; m < j; m += k - 1)
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);

                if ((len - 1) % (k - 1) == 0)
                    dp[i][j] += pre[j + 1] - pre[i];
            }
        }

        return dp[0][n - 1];
    }
};