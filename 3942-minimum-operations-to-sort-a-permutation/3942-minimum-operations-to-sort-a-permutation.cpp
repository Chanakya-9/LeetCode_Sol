class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int pos0 = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }

        bool can_asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos0 + i) % n] != i) {
                can_asc = false;
                break;
            }
        }

        bool can_desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos0 - i + n) % n] != i) {
                can_desc = false;
                break;
            }
        }

        if (!can_asc && !can_desc) return -1;

        int ans = INT_MAX;

        if (can_asc) {
            ans = min(ans, pos0);
            ans = min(ans, 2 + (n - pos0) % n);
        }

        if (can_desc) {
            ans = min(ans, 1 + (pos0 + 1) % n);
            ans = min(ans, 1 + (n - 1 - pos0));
        }

        return ans;
    }
};