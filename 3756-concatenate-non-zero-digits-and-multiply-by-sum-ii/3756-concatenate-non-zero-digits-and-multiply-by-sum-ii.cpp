class Solution {
    static const int MOD = 1e9 + 7;

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digits;
        vector<int> idx(n + 1);

        // idx[i] = number of non-zero digits before index i
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            idx[i] = cnt;
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                cnt++;
            }
        }
        idx[n] = cnt;

        int k = digits.size();

        // powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefHash[i] = value of first i non-zero digits
        vector<long long> prefHash(k + 1, 0);

        // prefSum[i] = sum of first i non-zero digits
        vector<long long> prefSum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            prefHash[i + 1] = (prefHash[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int L = idx[l];
            int R = idx[r + 1] - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefHash[R + 1] - prefHash[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};