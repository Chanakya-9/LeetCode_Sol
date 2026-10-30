class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (k < 1) return -1;
        if (n == 1) return 0;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, -1));
        priority_queue<tuple<long long, int, int>, 
                       vector<tuple<long long, int, int>>, 
                       greater<tuple<long long, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();

            if (d > dist[u][c]) continue;
            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                int nc = (labels[v] == labels[u]) ? (c + 1) : 1;
                if (nc > k) continue;

                if (dist[v][nc] == -1 || d + w < dist[v][nc]) {
                    dist[v][nc] = d + w;
                    pq.push({dist[v][nc], v, nc});
                }
            }
        }

        return -1;
    }
};