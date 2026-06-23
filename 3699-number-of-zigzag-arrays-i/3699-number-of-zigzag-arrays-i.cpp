class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> prefUp(m + 1), prefDown(m + 1);
        vector<int> newUp(m + 1), newDown(m + 1);

        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = prefUp[i - 1] + up[i];
                if (prefUp[i] >= MOD) prefUp[i] -= MOD;

                prefDown[i] = prefDown[i - 1] + down[i];
                if (prefDown[i] >= MOD) prefDown[i] -= MOD;
            }

            int totalUp = prefUp[m];

            for (int x = 1; x <= m; x++) {
                newUp[x] = prefDown[x - 1];

                newDown[x] = totalUp - prefUp[x];
                if (newDown[x] < 0) newDown[x] += MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int x = 1; x <= m; x++) {
            ans += up[x];
            ans += down[x];
        }

        return ans % MOD;
    }
};