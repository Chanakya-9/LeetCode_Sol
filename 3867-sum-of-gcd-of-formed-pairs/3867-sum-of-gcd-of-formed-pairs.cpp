class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        int mx = 0;

        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            p[i] = gcd(nums[i], mx);
        }

        sort(p.begin(), p.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += gcd(p[l], p[r]);
            l++;
            r--;
        }

        return ans;
    }
};