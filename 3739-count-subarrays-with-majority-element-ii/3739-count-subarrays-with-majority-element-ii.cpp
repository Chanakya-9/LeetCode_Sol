class Solution {
public:
    class Fenwick {
    public:
        int n;
        vector<int> bit;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                pref[i + 1] = pref[i] + 1;
            else
                pref[i + 1] = pref[i] - 1;
        }

        vector<int> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick bit(comp.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

        
            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};