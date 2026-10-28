class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                bitset<1024> from_prev;
                if (i > 0) from_prev |= dp[i - 1][j];
                if (j > 0) from_prev |= dp[i][j - 1];

                int val = grid[i][j];
                for (int x = 0; x < 1024; x++) {
                    if (from_prev.test(x)) {
                        dp[i][j].set(x ^ val);
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1].test(x)) {
                return x;
            }
        }

        return 0;
    }
};