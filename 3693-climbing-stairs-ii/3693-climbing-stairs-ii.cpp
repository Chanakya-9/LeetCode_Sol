class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 1) return costs[0] + 1;
        
        int a = 0;
        int b = costs[0] + 1;
        int c = min(b + 1, a + 4) + costs[1];
        
        for (int i = 3; i <= n; i++) {
            int d = min({c + 1, b + 4, a + 9}) + costs[i - 1];
            a = b;
            b = c;
            c = d;
        }
        
        return c;
    }
};