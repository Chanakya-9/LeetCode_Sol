#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isValidPathPossible(int n, const vector<vector<pair<int, int>>>& adj, 
                             const vector<int>& topoOrder, const vector<bool>& online, 
                             long long k, int minScoreBound) {
        
        vector<long long> dist(n, 1e16);
        dist[0] = 0;

        for (int u : topoOrder) {
            if (dist[u] >= 1e16) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (weight >= minScoreBound && online[v]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist[n - 1] <= k;
    }

    void dfs(int u, const vector<vector<pair<int, int>>>& adj, 
             vector<bool>& visited, vector<int>& topoOrder) {
        visited[u] = true;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                dfs(v, adj, visited, topoOrder);
            }
        }
        topoOrder.push_back(u);
    }

    vector<int> getTopoSort(int n, const vector<vector<pair<int, int>>>& adj) {
        vector<bool> visited(n, false);
        vector<int> topoOrder;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, topoOrder);
            }
        }
        reverse(topoOrder.begin(), topoOrder.end());
        return topoOrder;
    }

public:
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int n = online.size(); 
        
        vector<vector<pair<int, int>>> adj(n);
        vector<int> uniqueCosts;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            adj[u].push_back({v, cost});
            uniqueCosts.push_back(cost);
        }

        vector<int> topoOrder = getTopoSort(n, adj);

        sort(uniqueCosts.begin(), uniqueCosts.end());
        uniqueCosts.erase(unique(uniqueCosts.begin(), uniqueCosts.end()), uniqueCosts.end());

        int low = 0, high = uniqueCosts.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int candidateScore = uniqueCosts[mid];

            if (isValidPathPossible(n, adj, topoOrder, online, k, candidateScore)) {
                ans = candidateScore;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};