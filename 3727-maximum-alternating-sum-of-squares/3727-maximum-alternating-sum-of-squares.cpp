class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> a;
        for (int x : nums)
            a.push_back(1LL * x * x);

        sort(a.rbegin(), a.rend());

        long long ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i < (a.size() + 1) / 2)
                ans += a[i];
            else
                ans -= a[i];
        }

        return ans;
    }
};