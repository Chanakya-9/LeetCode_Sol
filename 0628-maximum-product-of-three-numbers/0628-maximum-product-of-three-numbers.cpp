class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        return max(nums[m - 1] * nums[m - 2] * nums[m - 3],
                   nums[m - 1] * nums[0] * nums[1]);
    }
};