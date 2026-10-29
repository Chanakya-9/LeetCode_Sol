class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    int N;

    void updateBit(int idx, int val) {
        for (; idx <= N; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int queryBit(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        tin[u] = ++timer;
        up[u][0] = p;
        depth[u] = d;

        for (int i = 1; i < 17; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
        tout[u] = timer;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = 16; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = 16; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(17, 0));
        bit.assign(n + 1, 0);

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0, 0, adj);

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            updateBit(tin[i], mask[i]);
            if (tout[i] + 1 <= n) {
                updateBit(tout[i] + 1, mask[i]);
            }
        }

        vector<bool> ans;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u = 0, idx = 7;
                while (q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                char c = q[idx + 1];

                int old_mask = mask[u];
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;

                mask[u] = new_mask;
                updateBit(tin[u], diff);
                if (tout[u] + 1 <= n) {
                    updateBit(tout[u] + 1, diff);
                }
            } else {
                int u = 0, v = 0, idx = 6;
                while (q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                idx++;
                while (idx < q.size()) {
                    v = v * 10 + (q[idx] - '0');
                    idx++;
                }

                int lca = getLCA(u, v);
                int path_mask = queryBit(tin[u]) ^ queryBit(tin[v]) ^ mask[lca];

                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};