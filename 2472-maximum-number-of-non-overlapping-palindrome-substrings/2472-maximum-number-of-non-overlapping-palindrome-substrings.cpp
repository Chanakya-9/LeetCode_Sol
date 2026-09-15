class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);

            for (int l = i, r = i; l >= 0 && r < n; l--, r++) {
                int len = r - l + 1;
                if (s[l] != s[r]) break;
                if (len >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
            }

            for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
                int len = r - l + 1;
                if (s[l] != s[r]) break;
                if (len >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
            }
        }

        return dp[n];
    }
};