class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for (int v = 0; v < adj.size(); ++v) {
            if (adj[u][v] == 1 && !vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};