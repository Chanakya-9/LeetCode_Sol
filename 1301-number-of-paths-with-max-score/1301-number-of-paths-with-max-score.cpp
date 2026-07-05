class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        int m = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n,
                                          vector<pair<int, int>>(n, {-1, 0}));

        dp[n - 1][n - 1] = {0, 1};

        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (b[r][c] == 'X' || (r == n - 1 && c == n - 1))
                    continue;

                int v = (b[r][c] == 'E') ? 0 : b[r][c] - '0';
                for (int i : {0, 1}) {
                    for (int j : {0, 1}) {
                        if (i == 0 && j == 0)
                            continue;
                        int nr = r + i, nc = c + j;
                        if (nr < n && nc < n && dp[nr][nc].first != -1) {
                            int ns = dp[nr][nc].first + v;
                            if (ns > dp[r][c].first)
                                dp[r][c] = {ns, dp[nr][nc].second};
                            else if (ns == dp[r][c].first)
                                dp[r][c].second =
                                    (dp[r][c].second + dp[nr][nc].second) % m;
                        }
                    }
                }
            }
        }
        return dp[0][0].first == -1
                   ? vector<int>{0, 0}
                   : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};