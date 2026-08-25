class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int p = 0;
        int n = nums.size();

        for (int x = k; ; x += k) {
            while (p < n && nums[p] < x) {
                p++;
            }

            if (p == n || nums[p] > x) {
                return x;
            }

            p++;   
        }
    }
};