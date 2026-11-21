class Solution {
    void findNewParents(int u, const vector<vector<int>>& adj, const string& s, vector<int>& last_seen, vector<int>& new_parent) {
        int c = s[u] - 'a';
        int prev = last_seen[c];
        if (u != 0 && prev != -1) {
            new_parent[u] = prev;
        }
        last_seen[c] = u;
        for (int v : adj[u]) {
            findNewParents(v, adj, s, last_seen, new_parent);
        }
        last_seen[c] = prev;
    }

    int calcSizes(int u, const vector<vector<int>>& adj, vector<int>& ans) {
        int sz = 1;
        for (int v : adj[u]) {
            sz += calcSizes(v, adj, ans);
        }
        return ans[u] = sz;
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);
        findNewParents(0, adj, s, last_seen, new_parent);

        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; i++) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        calcSizes(0, new_adj, ans);
        return ans;
    }
};