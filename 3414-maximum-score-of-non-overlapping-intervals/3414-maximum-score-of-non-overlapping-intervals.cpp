class Solution {
    struct Item {
        int l, r, w, id;
    };

    struct Node {
        long long val = 0;
        vector<int> idx;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Item> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
            return x.l < y.l;
        });

        vector<int> next_idx(n);
        for (int i = 0; i < n; i++) {
            int low = i + 1, high = n - 1, ans = n;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (a[mid].l > a[i].r) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            next_idx[i] = ans;
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        auto update = [](Node& target, const Node& cand) {
            if (cand.val > target.val) {
                target = cand;
            } else if (cand.val == target.val && target.val > 0) {
                if (target.idx.empty() || cand.idx < target.idx) {
                    target = cand;
                }
            }
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];

                Node pick;
                int nxt = next_idx[i];
                pick.val = a[i].w + dp[nxt][k - 1].val;
                pick.idx = dp[nxt][k - 1].idx;
                pick.idx.push_back(a[i].id);
                sort(pick.idx.begin(), pick.idx.end());

                update(dp[i][k], pick);
            }
        }

        return dp[0][4].idx;
    }
};