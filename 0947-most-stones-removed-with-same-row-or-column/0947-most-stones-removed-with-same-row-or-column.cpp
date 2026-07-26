class Solution {
public:
    void dfs(vector<vector<int>> &gp, vector<int> &vis, int src) {

        vis[src] = true;

        for (auto nei : gp[src]) {
            if (!vis[nei]) {
                dfs(gp, vis, nei);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        vector<vector<int>> gp(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    gp[i].push_back(j);
                    gp[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, false);

        int comp = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                comp++;
                dfs(gp, vis, i);
            }
        }

        return n - comp;
    }
};