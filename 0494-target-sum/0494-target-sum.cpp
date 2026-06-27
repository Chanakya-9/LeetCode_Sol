class Solution {
    int ans = 0;
    int tar;
    vector<int> num;
    int n;
    int helper(int i, int sum) {
        if (i == n) {
            if (sum == tar) {
                ans++;
            }
            return 0;
        }
        helper(i + 1, sum + num[i]);
        helper(i + 1, sum - num[i]);

        return 0;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        ans = 0;
        tar=target;
        num=nums;
        n=nums.size();;
        helper(0,0);
        return ans;
    }
};