class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> cur;
            for (int j = i; j < i + k; j++) {
                cur.insert(nums[j]);
            }
            for (int x : cur) {
                cnt[x]++;
            }
        }

        int ans = -1;
        for (auto& [val, freq] : cnt) {
            if (freq == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};