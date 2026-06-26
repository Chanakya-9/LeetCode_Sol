class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0;
        int right = 1;
        int ans = 0;

        while (right < n) {
            if (prices[left] < prices[right]) {
                int curr = prices[right] - prices[left];
                ans = max(curr, ans);
            } else {
                left = right;
            }
            right++;
        }
        return ans;
    }
};