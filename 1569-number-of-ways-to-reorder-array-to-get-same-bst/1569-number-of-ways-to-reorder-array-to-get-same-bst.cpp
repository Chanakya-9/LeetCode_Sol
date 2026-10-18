// static const int _ = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();

class Solution {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAXN = 1005;

    static inline long long fact[MAXN];
    static inline long long invFact[MAXN];
    static inline bool initialized = false;

    static long long modPow(long long base, int exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    static void precompute() {
        if (initialized) return;
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MAXN - 1] = modPow(fact[MAXN - 1], MOD - 2);
        for (int i = MAXN - 2; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        initialized = true;
    }

    static inline long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int leftChild[MAXN];
    int rightChild[MAXN];

    pair<long long, int> dfs(int u) {
        if (u == -1) return {1, 0};

        auto [lWays, lSize] = dfs(leftChild[u]);
        auto [rWays, rSize] = dfs(rightChild[u]);

        int totalSize = lSize + rSize + 1;
        long long ways = nCr(lSize + rSize, lSize);
        ways = (ways * lWays) % MOD;
        ways = (ways * rWays) % MOD;

        return {ways, totalSize};
    }

public:
    int numOfWays(vector<int>& nums) {
        precompute();

        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            leftChild[i] = -1;
            rightChild[i] = -1;
        }

        int root = nums[0];
        for (int i = 1; i < n; i++) {
            int val = nums[i];
            int curr = root;
            while (true) {
                if (val < curr) {
                    if (leftChild[curr] == -1) {
                        leftChild[curr] = val;
                        break;
                    }
                    curr = leftChild[curr];
                } else {
                    if (rightChild[curr] == -1) {
                        rightChild[curr] = val;
                        break;
                    }
                    curr = rightChild[curr];
                }
            }
        }

        long long totalWays = dfs(root).first;
        return (totalWays - 1 + MOD) % MOD;
    }
};