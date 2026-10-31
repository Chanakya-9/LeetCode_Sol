class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<array<int, 3>>> nxtR(m, vector<array<int, 3>>(n, {-1, -1, -1}));
        vector<vector<array<int, 3>>> nxtD(m, vector<array<int, 3>>(n, {-1, -1, -1}));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        nxtR[i][j] = {i, j + 1, 0};
                    } else {
                        if (i + 1 < m) {
                            if (grid[i + 1][j + 1] == 0) {
                                nxtR[i][j] = {i + 1, j + 1, 1};
                            } else {
                                nxtR[i][j] = nxtD[i][j + 1];
                            }
                        }
                    }
                }

                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        nxtD[i][j] = {i + 1, j, 1};
                    } else {
                        if (j + 1 < n) {
                            if (grid[i + 1][j + 1] == 0) {
                                nxtD[i][j] = {i + 1, j + 1, 0};
                            } else {
                                nxtD[i][j] = nxtR[i + 1][j];
                            }
                        }
                    }
                }
            }
        }

        vector<vector<array<int, 2>>> dp(m, vector<array<int, 2>>(n, {0, 0}));

        auto r_step = nxtR[0][0];
        if (r_step[0] != -1) {
            dp[r_step[0]][r_step[1]][r_step[2]] = (dp[r_step[0]][r_step[1]][r_step[2]] + 1) % MOD;
        }

        auto d_step = nxtD[0][0];
        if (d_step[0] != -1) {
            dp[d_step[0]][d_step[1]][d_step[2]] = (dp[d_step[0]][d_step[1]][d_step[2]] + 1) % MOD;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == m - 1 && j == n - 1) continue;

                int ways = (dp[i][j][0] + dp[i][j][1]) % MOD;
                if (ways == 0) continue;

                if (nxtR[i][j][0] != -1) {
                    auto [nr, nc, nd] = nxtR[i][j];
                    dp[nr][nc][nd] = (dp[nr][nc][nd] + ways) % MOD;
                }

                if (nxtD[i][j][0] != -1) {
                    auto [nr, nc, nd] = nxtD[i][j];
                    dp[nr][nc][nd] = (dp[nr][nc][nd] + ways) % MOD;
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};