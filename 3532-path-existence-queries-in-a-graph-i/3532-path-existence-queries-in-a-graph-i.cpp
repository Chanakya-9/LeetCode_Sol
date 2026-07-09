class Solution {
    int k;
    vector<int> par;
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        k = n;
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                par[i] = find(i - 1);
            }
        }
        vector<bool> ans;

        for (auto q : queries) {
            if (find(q[0]) == find(q[1])) {
                ans.push_back(true);
            } else {

                ans.push_back(false);
            }
        }
        return ans;
    }
};