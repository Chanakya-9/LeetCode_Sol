
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> free;

        priority_queue<pair<long long,pair<int,int>>,
            vector<pair<long long,pair<int,int>>>,
            greater<pair<long long,pair<int,int>>>> busy;

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans(tasks.size());

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && busy.top().first <= time) {
                auto [finish, server] = busy.top();
                busy.pop();
                free.push(server);
            }

            if(free.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    auto [finish, server] = busy.top();
                    busy.pop();
                    free.push(server);
                }
            }

            auto [weight, idx] = free.top();
            free.pop();

            ans[i] = idx;

            busy.push({time + tasks[i], {weight, idx}});
        }

        return ans;
    }
};
