class Solution {
    struct MedianFinder {
        multiset<int> left, right;
        long long sum_l = 0, sum_r = 0;
        int target_l;

        MedianFinder(int x) : target_l((x + 1) / 2) {}

        void balance() {
            while (left.size() > target_l) {
                int val = *left.rbegin();
                right.insert(val);
                sum_r += val;
                sum_l -= val;
                left.erase(prev(left.end()));
            }
            while (left.size() < target_l && !right.empty()) {
                int val = *right.begin();
                left.insert(val);
                sum_l += val;
                sum_r -= val;
                right.erase(right.begin());
            }
        }

        void add(int num) {
            if (left.empty() || num <= *left.rbegin()) {
                left.insert(num);
                sum_l += num;
            } else {
                right.insert(num);
                sum_r += num;
            }
            balance();
        }

        void remove(int num) {
            auto it = left.find(num);
            if (it != left.end()) {
                sum_l -= num;
                left.erase(it);
            } else {
                sum_r -= num;
                right.erase(right.find(num));
            }
            balance();
        }

        long long get_cost() {
            long long med = *left.rbegin();
            return (1LL * left.size() * med - sum_l) + (sum_r - 1LL * right.size() * med);
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        MedianFinder mf(x);

        for (int i = 0; i < x; i++) {
            mf.add(nums[i]);
        }
        cost[0] = mf.get_cost();

        for (int i = x; i < n; i++) {
            mf.remove(nums[i - x]);
            mf.add(nums[i]);
            cost[i - x + 1] = mf.get_cost();
        }

        vector<long long> dp(n + 1, 0);

        for (int j = 1; j <= k; j++) {
            vector<long long> next_dp(n + 1, 1e18);
            for (int i = j * x; i <= n; i++) {
                next_dp[i] = min(next_dp[i - 1], dp[i - x] + cost[i - x]);
            }
            dp = move(next_dp);
        }

        return dp[n];
    }
};
