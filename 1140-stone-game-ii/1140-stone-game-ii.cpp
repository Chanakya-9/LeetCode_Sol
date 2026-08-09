class Solution {
    int dfs(int idx, int m, vector<int>& piles, vector<int>& remain, vector<vector<int>>& memo) {
        int n = piles.size();
        if (idx == n) return 0;
        if (idx + 2 * m >= n) return remain[idx];
        if (memo[idx][m]) return memo[idx][m];
        
        int bestScore = 0;
        for (int x = 1; x <= 2 * m; x++) {
            int oppScore = dfs(idx + x, max(m, x), piles, remain, memo);
            bestScore = max(bestScore, remain[idx] - oppScore);
        }
        
        return memo[idx][m] = bestScore;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, 0));
        vector<int> remain = piles;
        
        for (int i = n - 2; i >= 0; i--) {
            remain[i] += remain[i + 1];
        }
            
        return dfs(0, 1, piles, remain, memo);
    }
};