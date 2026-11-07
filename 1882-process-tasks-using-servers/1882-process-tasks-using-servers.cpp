
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> available;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        int n = servers.size();
        vector<int> ans(tasks.size());

        for(int i = 0; i < n; i++)
            available.push({servers[i], i});

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();
                available.push({servers[idx], idx});
            }

            if(available.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    int idx = busy.top().second;
                    busy.pop();
                    available.push({servers[idx], idx});
                }
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};
