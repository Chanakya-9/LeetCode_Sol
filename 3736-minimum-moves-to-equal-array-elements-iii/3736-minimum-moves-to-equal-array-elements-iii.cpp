class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];

        for (int x : nums) {
            if (x > maxi) {
                maxi = x;
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans += abs(x - maxi);
        }
        return ans;
    }
};