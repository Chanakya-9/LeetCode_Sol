class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        long long mod = 1e9 + 7;

        vector<vector<pair<int, int>>> gp(n);

        for (auto &r : roads) {
            gp[r[0]].push_back({r[1], r[2]});
            gp[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            long long d = curr.first;
            int u = curr.second;

            if (d > dist[u]) {
                continue;
            }

            for (auto p : gp[u]) {

                int v = p.first;
                int w = p.second;

                if (dist[v] > d + w) {

                    dist[v] = d + w;
                    ways[v] = ways[u];

                    pq.push({dist[v], v});

                } else if (dist[v] == d + w) {

                    ways[v] += ways[u];
                    ways[v] %= mod;
                }
            }
        }

        return ways[n - 1];
    }
};