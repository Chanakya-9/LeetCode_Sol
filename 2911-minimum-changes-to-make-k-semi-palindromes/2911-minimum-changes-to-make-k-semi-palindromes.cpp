class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> cost(n, vector<int>(n, 1e5));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int min_c = 1e5;
                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) continue;
                    int cur_c = 0;
                    for (int g = 0; g < d; ++g) {
                        int left = i + g;
                        int right = i + len - d + g;
                        while (left < right) {
                            if (s[left] != s[right]) cur_c++;
                            left += d;
                            right -= d;
                        }
                    }
                    min_c = min(min_c, cur_c);
                }
                cost[i][j] = min_c;
            }
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(n, 1e5));
        for (int j = 1; j < n; ++j) {
            dp[1][j] = cost[0][j];
        }
        
        for (int p = 2; p <= k; ++p) {
            for (int j = p * 2 - 1; j < n; ++j) {
                for (int i = (p - 1) * 2; i < j; ++i) {
                    dp[p][j] = min(dp[p][j], dp[p - 1][i - 1] + cost[i][j]);
                }
            }
        }
        
        return dp[k][n - 1];
    }
};