class Solution {
public:
    struct SparseTable {
        int n;
        vector<vector<int>> st;
        vector<int> lg;

        void build(vector<int> &a) {
            n = a.size();
            if (n == 0) return;

            lg.assign(n + 1, 0);

            for (int i = 2; i <= n; i++) {
                lg[i] = lg[i / 2] + 1;
            }

            st.assign(lg[n] + 1, vector<int>(n));
            st[0] = a;

            for (int j = 1; j <= lg[n]; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[j][i] = max(st[j - 1][i],
                                   st[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        int query(int l, int r) {
            if (l > r || l < 0 || r >= n) return 0;

            int j = lg[r - l + 1];

            return max(st[j][l],
                       st[j][r - (1 << j) + 1]);
        }
    };

    struct Node {
        int l, r, len;
    };

    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>> &queries) {

        int n = s.size();

        int one = 0;
        vector<Node> z;

        for (int i = 0; i < n;) {

            if (s[i] == '1') {
                one++;
                i++;
                continue;
            }

            int j = i;

            while (j < n && s[j] == '0') {
                j++;
            }

            z.push_back({i, j - 1, j - i});
            i = j;
        }

        int m = z.size();

        vector<int> a(max(0, m - 1));

        for (int i = 0; i < m - 1; i++) {
            a[i] = z[i].len + z[i + 1].len;
        }

        SparseTable st;
        st.build(a);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            auto it1 = lower_bound(z.begin(), z.end(), l,
                                   [](Node &x, int v) {
                                       return x.r < v;
                                   });

            auto it2 = upper_bound(z.begin(), z.end(), r,
                                   [](int v, Node &x) {
                                       return v < x.l;
                                   });

            int gl = it1 - z.begin();
            int gr = it2 - z.begin() - 1;

            if (gl >= gr) {
                ans.push_back(one);
                continue;
            }

            int left = min(r, z[gl].r) - max(l, z[gl].l) + 1;
            int right = min(r, z[gr].r) - max(l, z[gr].l) + 1;

            if (gl + 1 == gr) {
                ans.push_back(one + left + right);
                continue;
            }

            int best = max(left + z[gl + 1].len,
                           right + z[gr - 1].len);

            if (gl + 1 <= gr - 2) {
                best = max(best, st.query(gl + 1, gr - 2));
            }

            ans.push_back(one + best);
        }

        return ans;
    }
};