class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0, nz = 0;
        for (int x : nums) {
            total ^= x;
            if (x > 0)
                nz++;
        }
        if (nz == 0)
            return 0;
        return total != 0 ? (int)nums.size() : (int)nums.size() - 1;
    }
};