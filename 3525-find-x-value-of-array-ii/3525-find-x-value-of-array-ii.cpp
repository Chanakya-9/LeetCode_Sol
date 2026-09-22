class Solution {
    int n, k_mod;
    vector<vector<int>> tree;
    vector<int> prod;
    vector<int> arr;

    void combine(int node, int l_child, int r_child) {
        prod[node] = (1LL * prod[l_child] * prod[r_child]) % k_mod;
        int p = prod[l_child];
        for (int i = 0; i < k_mod; i++) {
            tree[node][i] = tree[l_child][i];
        }
        for (int i = 0; i < k_mod; i++) {
            tree[node][(1LL * p * i) % k_mod] += tree[r_child][i];
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int m = arr[l] % k_mod;
            tree[node][m] = 1;
            prod[node] = m;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        combine(node, 2 * node, 2 * node + 1);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            fill(tree[node].begin(), tree[node].end(), 0);
            int m = val % k_mod;
            tree[node][m] = 1;
            prod[node] = m;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        combine(node, 2 * node, 2 * node + 1);
    }

    void query(int node, int l, int r, int ql, int qr, vector<int>& cur_cnt, int& cur_prod) {
        if (ql <= l && r <= qr) {
            for (int i = 0; i < k_mod; i++) {
                cur_cnt[(1LL * cur_prod * i) % k_mod] += tree[node][i];
            }
            cur_prod = (1LL * cur_prod * prod[node]) % k_mod;
            return;
        }
        int mid = (l + r) / 2;
        if (ql <= mid) query(2 * node, l, mid, ql, qr, cur_cnt, cur_prod);
        if (qr > mid) query(2 * node + 1, mid + 1, r, ql, qr, cur_cnt, cur_prod);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        k_mod = k;
        arr = nums;

        tree.assign(4 * n, vector<int>(k_mod, 0));
        prod.assign(4 * n, 1);

        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], target = q[3];
            update(1, 0, n - 1, idx, val);

            vector<int> cnt(k_mod, 0);
            int p = 1;
            query(1, 0, n - 1, start, n - 1, cnt, p);

            ans.push_back(cnt[target]);
        }

        return ans;
    }
};