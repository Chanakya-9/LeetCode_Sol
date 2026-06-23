class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int, int>> p;
        int n = pairs.size();
        for (int i = 0; i < n; i++) {
            p.push_back({pairs[i][1], pairs[i][0]});
        }
        sort(p.begin(), p.end());
        int ans = 0;

        int time = -2000;
        for (auto x : p) {
            if (x.second > time) {
                ans++;
                time = x.first;
            }
        }

        return ans;
    }
};