class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        vector<long long> C(2 * k + 1, 0);
        C[0] = 1;

        int N = n + k - 1;
        int K = 2 * k;

        for (int i = 1; i <= N; i++) {
            for (int j = min(i, K); j > 0; j--) {
                C[j] = (C[j] + C[j - 1]) % mod;
            }
        }

        return C[K];
    }
};