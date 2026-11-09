class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> counts(k, 0);
        set<int> free_servers;
        for (int i = 0; i < k; ++i) {
            free_servers.insert(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_servers;
        
        for (int i = 0; i < arrival.size(); ++i) {
            int arr = arrival[i];
            int duration = load[i];
            
            while (!busy_servers.empty() && busy_servers.top().first <= arr) {
                free_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            if (free_servers.empty()) {
                continue;
            }
            
            auto it = free_servers.lower_bound(i % k);
            if (it == free_servers.end()) {
                it = free_servers.begin();
            }
            
            int server_id = *it;
            counts[server_id]++;
            free_servers.erase(it);
            busy_servers.push({arr + duration, server_id});
        }
        
        int max_reqs = *max_element(counts.begin(), counts.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_reqs) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};