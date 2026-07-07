class Solution {
    int MOD = 1e9 + 7;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> digit;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int k = digit.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> pref(k + 1, 0);
        vector<long long> prefSum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            pref[i + 1] = (pref[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            int len = R - L + 1;

            long long x =
                (pref[R + 1] - pref[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};