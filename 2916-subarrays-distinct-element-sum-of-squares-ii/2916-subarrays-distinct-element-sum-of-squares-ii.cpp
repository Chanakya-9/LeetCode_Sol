class Solution {
    long long MOD = 1e9 + 7;
    vector<long long> tree_sum, tree_sq, lazy;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        val %= MOD;

        tree_sq[node] =
            (tree_sq[node] + 2LL * val % MOD * tree_sum[node] % MOD +
             val * val % MOD * len % MOD) %
            MOD;
        tree_sum[node] = (tree_sum[node] + val * len % MOD) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) {
            update(node * 2, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        }
        tree_sum[node] = (tree_sum[node * 2] + tree_sum[node * 2 + 1]) % MOD;
        tree_sq[node] = (tree_sq[node * 2] + tree_sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n + 1, 0);
        tree_sq.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);

        unordered_map<int, int> last_pos;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;

            update(1, 1, n, prev + 2, j + 1, 1);

            ans = (ans + tree_sq[1]) % MOD;
            last_pos[nums[j]] = j;
        }

        return ans;
    }
};