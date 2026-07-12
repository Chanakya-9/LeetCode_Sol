class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int v = 0;
                int deg = 0;

                vector<int> q;
                q.push_back(i);
                vis[i] = true;
                
                size_t h = 0;
                while (h < q.size()) {
                    int curr = q[h++];
                    v++;
                    deg += adj[curr].size();

                    for (int nxt : adj[curr]) {
                        if (!vis[nxt]) {
                            vis[nxt] = true;
                            q.push_back(nxt);
                        }
                    }
                }

                if (deg == v * (v - 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};