class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(mx + 1, 0);
        for (int x : nums) cnt[x]++;

        vector<long long> gcd_count(mx + 1, 0);
        for (int i = mx; i >= 1; --i) {
            long long c = 0;
            for (int j = i; j <= mx; j += i) {
                c += cnt[j];
            }
            long long total_pairs = c * (c - 1) / 2;
            for (int j = 2 * i; j <= mx; j += i) {
                total_pairs -= gcd_count[j];
            }
            gcd_count[i] = total_pairs;
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; ++i) {
            pref[i] = pref[i - 1] + gcd_count[i];
        }

        vector<int> ans;
        for (long long q : queries) {
            int idx = upper_bound(pref.begin(), pref.end(), q) - pref.begin();
            ans.push_back(idx);
        }

        return ans;
    }
};