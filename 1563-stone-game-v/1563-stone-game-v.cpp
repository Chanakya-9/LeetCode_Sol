class Solution {
    int dp[501][501];
    int pref[501];

    int solve(int l, int r) {
        if (l == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int i = l; i < r; i++) {
            int ls = pref[i + 1] - pref[l];
            int rs = pref[r + 1] - pref[i + 1];

            if (ls < rs) {
                ans = max(ans, ls + solve(l, i));
            } else if (rs < ls) {
                ans = max(ans, rs + solve(i + 1, r));
            } else {
                ans = max(ans, ls + max(solve(l, i), solve(i + 1, r)));
            }
        }
        return dp[l][r] = ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1);
    }
};