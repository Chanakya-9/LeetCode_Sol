class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        if (mn % 2 != 0) return true;

        for (int x : nums) {
            if (x % 2 != 0) return false;
        }

        return true;
    }
};