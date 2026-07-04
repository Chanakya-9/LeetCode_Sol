class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }

        int m = INT_MAX;
        vector<bool> v(n + 1, false);
        queue<int> q;
        q.push(1);
        v[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& edge : g[u]) {
                m = min(m, edge.second);
                if (!v[edge.first]) {
                    v[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return m;
    }
};