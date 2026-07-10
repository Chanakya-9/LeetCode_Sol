class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++) a.push_back({nums[i], i});
        sort(a.begin(), a.end());

        vector<int> pos(n), comp(n);
        int cid = 0;
        for(int i = 0; i < n; i++) {
            if(i && a[i].first - a[i - 1].first > maxDiff) cid++;
            comp[i] = cid;
            pos[a[i].second] = i;
        }

        vector<int> nxt(n);
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && comp[j + 1] == comp[i] && a[j + 1].first - a[i].first <= maxDiff) j++;
            nxt[i] = j;
            if(j == i) j++;
        }

        int LG = 20;
        vector<vector<int>> up(LG, vector<int>(n));
        up[0] = nxt;
        for(int k = 1; k < LG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        for(auto &q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }
            if(u == v) {
                ans.push_back(0);
                continue;
            }
            if(u > v) swap(u, v);

            int cur = u, res = 0;
            for(int k = LG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    res += 1 << k;
                }
            }
            ans.push_back(res + 1);
        }

        return ans;
    }
};