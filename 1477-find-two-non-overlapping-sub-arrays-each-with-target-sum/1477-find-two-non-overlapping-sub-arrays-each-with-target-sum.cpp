class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0, ans = INT_MAX, best = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            mp[sum] = i;

            if (mp.count(sum - target)) {
                int len = i - mp[sum - target];
                if (mp[sum - target] >= 0 && min_len[mp[sum - target]] != INT_MAX) {
                    ans = min(ans, len + min_len[mp[sum - target]]);
                }
                best = min(best, len);
            }

            min_len[i] = best;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
