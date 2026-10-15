class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {

            for (int i = 0; i <= n - k; i++) {
                vector<bool> check(101, false);
                int distinct = 0;

                for (int j = i; j < i + k; j++) {
                    if (!check[nums[j]]) {
                        check[nums[j]] = true;
                        distinct++;
                    }
                }

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};