class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }

        int l = min(min_idx, max_idx);
        int r = max(min_idx, max_idx);

        int both_front = r + 1;
        int both_back = n - l;
        int from_both = (l + 1) + (n - r);

        return min({both_front, both_back, from_both});
    }
};
