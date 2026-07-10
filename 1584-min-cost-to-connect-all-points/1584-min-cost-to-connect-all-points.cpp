// class Solution {
//     vector<int> par;
//     int find(int x) {
//         if (par[x] == x) {
//             return x;
//         }
//         return par[x] = find(par[x]);
//     }

// public:
//     int minCostConnectPoints(vector<vector<int>>& p) {
//         int n = p.size();

//         vector<vector<int>> edge;

//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int dis = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
//                 edge.push_back({dis, i, j});
//             }
//         }

//         sort(edge.begin(), edge.end());

//         par.resize(n);
//         for (int i = 0; i < n; i++) {
//             par[i] = i;
//         }

//         int ans = 0;

//         for (auto e : edge) {
//             if (find(e[1]) != find(e[2])) {
//                 par[find(e[1])] = e[2];
//                 ans += e[0];
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);

        dist[0] = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!vis[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            vis[u] = true;
            ans += dist[u];

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int d = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);

                    dist[v] = min(dist[v], d);
                }
            }
        }

        return ans;
    }
};